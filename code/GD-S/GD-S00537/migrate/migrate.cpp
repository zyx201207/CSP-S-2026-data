#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,t,n,d,p,ans,x[2000001],l[2000001],r[2000001],nl[2000001],nr[2000001],num[2000001];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		memset(nl,0,sizeof(nl));
		memset(nr,0,sizeof(nr));
		memset(num,0,sizeof(num));
		cin>>n>>d;
		p=1;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			while(x[j]-x[p]>d){
				p++;
			}
			l[j]=p;
		}
		p=n;
		for(int j=n;j>=1;j--){
			while(x[p]-x[j]>d){
				p--;
			}
			r[j]=p;
			if(j<p-1){
				num[p]++;
			}
		}
		for(int j=1;j<=n;j++){
			ans+=num[l[j]+1];
		}
		for(int j=1;j<=n;j++){
			if(r[l[j]]==j){
				nl[j]=nl[l[j]]+1;
			}
			if((l[j]!=1)&&(r[l[l[j]]]==l[j]+1)){
				ans+=nl[l[l[j]]];
			}
		}
		for(int j=n;j>=1;j--){
			if(l[r[j]]==j){
				nr[j]=nr[r[j]]+1;
			}
			if((r[j]!=n)&&(l[r[r[j]]]==r[j]-1)){
				ans+=nr[r[r[j]]];
			}
		}
		for(int j=1;j<=n;j++){
			if((l[j]!=1)&&(r[l[l[j]]]==l[j]+1)&&(r[r[l[l[j]]]]==j)){
				ans+=nl[l[l[j]]]*nr[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
