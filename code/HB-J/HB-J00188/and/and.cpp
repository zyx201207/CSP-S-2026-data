#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],f[2005][2005],mx=-1e7;
void ff(int v,int k,int i){
	if(k==m){mx=max(mx,v);return;}
	for(;i<=n;i++){ff(v&a[i],k+1,i+1);}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){ff(a[i],1,i+1);}
	cout<<mx;
	return 0;
}
