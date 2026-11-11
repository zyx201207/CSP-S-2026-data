#include<bits/stdc++.h>
using namespace std;
long long n,m,a[522222],l[555555],r[555555],x[555555],s[555555],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(x[a[j]])l[t]=x[a[j]],r[t++]=j;
			x[a[j]]=j;
		}
		t=0;
		memset(x,0,sizeof(x));
		for(int j=i;j<=n;j++){
			while(l[t]==j)j=r[t],t++;
			x[a[j]]++;
		}
		for(int j=1;j<=m;j++)if(x[j])s[j]++;
		memset(x,0,sizeof(x));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		t=0;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}
