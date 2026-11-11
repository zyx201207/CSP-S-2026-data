#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ax,o[200005],cnt=1;
int v[200005];
void z(long long x,long long s){
	if(x>n){
		return;
	}
	if(s==m){
		for(int i=1;i<=n;i++){
			if(v[i]==1){
				o[cnt]=a[i];
				cnt+=1;
			}
		}
		for(int i=2;i<=m;i++){
			o[i]&=o[i-1];
			o[i-1]=0;
		}
		ax=max(ax,o[m]);
		o[m]=0;
		cnt=1;
		return;
	}
	v[x]=1;
	z(x+1,s+1);
	v[x]=0;
	z(x+1,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	z(1,0);
	cout<<ax;
	return 0;
} 
