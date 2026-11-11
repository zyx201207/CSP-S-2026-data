#include<bits/stdc++.h>
using namespace std;
long long l[500005];
struct node{
	int num;
	node* next;
};
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,c;
	cin >> a>>c;
	node* starting = (node*)malloc(sizeof(node));
	starting->next = starting;
	node* now = starting;
	for(int i = 0;i<a;i++) {
		now = now->next;
		int b;
		cin >> b;
		now = starting;
		if(now->num == b) {
			l[b]++;
			starting = (node*)malloc(sizeof(node));
			now = starting;
		}
		for(int j = 0;j<=i;j++) {
			if(now->next->num == b) {
				l[b]++;
				now = (node*)malloc(sizeof(node));
				now->num = b;
				break;
			}
			now = now->next; 
		} 
		now->num = b;
		now->next = (node*)malloc(sizeof(node));
	}
	for(long long i = 1;i<=a;i++)cout << l[i]<<" ";
	return 0;
}
