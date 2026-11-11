#include<bits/stdc++.h>
using namespace std;
int w[500005],stop[500005][20];
struct node{
	int name;
	int y;
};
vector<node> a[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	for(int i=0;i<m;i++){
		cin>>w[m];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a1,a2;
			cin>>a1>>a2;
			a[i].push_back({a1,a2});
		}
	}
	for(int i=0;i<p;i++){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
} 
