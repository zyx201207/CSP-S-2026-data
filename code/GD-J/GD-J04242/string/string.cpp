#include<bits/stdc++.h>
using namespace std;
struct ss
{
	long long s;
	char c;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,f=0;
	long long ans=0,maxs,mins;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].c;
	}
	int i=1,j=n;
	while(i<j)
	{
		
		if(a[i].s>a[j].s){f=1;maxs=a[i].s;mins=a[j].s;}
		else {maxs=a[j].s;mins=a[i].s;}
		if(a[i].c!=a[j].c)ans+=mins;
		
		maxs-=mins;
		mins=0;
		if(f==1){
			a[i].s=maxs;
			a[j].s=0;
			
		}
		else{
			a[i].s=0;
			a[j].s=maxs;
		}
		if(a[i].s==0)i++;
		if(a[j].s==0)j--;
	}
	cout<<ans;
}
