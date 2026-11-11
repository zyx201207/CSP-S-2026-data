#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c,n,m,d,q;
int w[maxn];
struct node{
	int k;
	int zd[maxn];
	int t[maxn];
}a[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++) cin>>a[i].zd[i]>>a[i].t[i];
	}
	
} 
