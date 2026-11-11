#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node{
    int id;
    int point;
    vector<Node*> next;
};

int count(vector<Node*> root,int end) {
    if (root.empty()) return 0;
    vector<Node*> map;
    int c = 0;
    for (Node* node : root) {
        if (node->id == end) {
            c++;
        }
        for (Node* n : node->next) {
        	map.push_back(n);
		}
    }
    if (c == 0) {
        return count(map,end);
    }
    return c;
}

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for (int i = 0;i < t;i++) {
        int n,d;
        cin >> n >> d;
        Node* points = new Node[n];
        for (int j = 0;j < n;j++) {
        	points[j].id = j;
            cin >> points[j].point;
        }
        for (int j = 0;j < n;j++) {
            Node point = points[j];
            int k = 1;
            while (points[j + k].point - points[j].point <= d)
            {
                point.next.push_back(&points[j + k]);
                k++;
            }
        }
        int c = 0;
        for (int j = 0;j < n;j++) {
            for (int k = j + 1;k < n;k++) {
                if (count(points[j].next,k) == 2) {
                	c++;
				}
            }
        }
        cout << c << endl;
    }
}
