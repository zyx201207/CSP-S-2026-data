#include<bits/stdc++.h>
using namespace std;
struct Node{
    vector<int> tow,ins;
    int t;
};
int w[500005];
vector<Node> zt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	int mid;
	for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int x,y;
            cin>>x>>y;
            mid=x;
        }
	}
	for(int i=0;i<q;i++){
        int b,e;
        cin>>b>>e;
        cout<<w[b-1]+w[e-1]+mid*2;
	}
}
