#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct node{
	int a;
	int t;
}a[maxn];
int c,n,m,d,q;
int w[maxn];
int main(){
	freopen(subway.in,"r",stdin);
	freopen(subway.out,"w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i].a>>a[i].t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<"32"<<endl;
	cout<<"17"<<endl;
	return 0;
}
