#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int p,n,m,a[500005],ma,mm,pp,ans;
	cin>>n>>m;
	for(int j,i=1;i<=n;i++){
		j=i;
		cin>>p;
		while(p<a[j-1]&&j>1){
			a[j-1]=a[j];
			j-=1;
		}
		a[j]=p;
	}
	ma=1;
	mm=1;
	p=1;
	pp=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			p+=1;
		}
		if(a[i]>a[i-1]){
			p=1;
			pp=i;
		}
		if(p>mm||(p==mm&&a[i]-a[i-1]<a[ma]-a[ma-1])){
			ma=pp;
			mm=p;
		}
	}
	ans=mm;
	for(int i=mm;i>=1&&m-(a[ma]-a[i])>=0;i--){
		ans+=1;
		m-=(a[ma]-a[i]);
	}
	int i=mm+1;
	while((a[i]-a[i-1])*ans<=m&&i<=n){
		ans+=1;
		m-=(a[i]-a[i-1])*(ans-1);
		i+=1;
	}
	cout<<ans;
	return 0;
} 
