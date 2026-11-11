#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x<y;}
long long m,n,ans=1,at,mi=1;
long long c[500001],k[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>c[i];}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		k[i]=c[i+1]-c[i];
		if((k[i-1]<k[i])&&i>1){
			mi=i;
		}
	}
	at=mi;
	for(int i=at,len=1;i<=n;i++){
		if(len*k[i]<=m){
			ans++;
			m-=len*k[i];
			len++;
		}
	}
	cout<<ans;
}
