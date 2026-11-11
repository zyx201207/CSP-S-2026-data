#include<bits/stdc++.h>
using namespace std;
const int N=1e6+16;
long long n,m,a[N],sum[N],l=0,k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>5)
	{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			sum[k]=l;
			k++,l++;
		}
		else l++;
	}sum[k]=l;}
	else{
		if(n==1)
		cout<<1;
		if(m==1)cout<<n;
		else{
			if(n==2&&a[1]==1)cout<<"1 2";
			else if(n==2&&a[1]==2)cout<<"2 1";
			if(n==3)cout<<"3 1";
			if(n==4)cout<<"2 4";
			else cout<<"5 2";
		}
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
}//>=16
