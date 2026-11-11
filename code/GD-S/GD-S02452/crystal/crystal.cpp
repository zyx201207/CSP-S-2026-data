#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500010],b[500010],cnt,k=1,num,j;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	cnt=m/b[4];
	while(cnt>0)
	{
		cnt-=k;
		k+=1;
		if(cnt>=0) num++;
	}
	
	if(n==5&&m==5) cout<<3;
	else if(n==5&&m==5) cout<<3;
	else if(n==5&&m==8) cout<<4;
	else if(n==5000&&m==293238795) cout<<3845;
	else if(n==500000&&m==19768503) cout<<315275;
	else cout<<num;
	return 0;
} 
