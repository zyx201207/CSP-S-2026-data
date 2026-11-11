#include<bits/stdc++.h>
using namespace std;

long long a[200005],s[200005],f[200005];

int n,m;
long long ans;

long long chk(int x){
	long long cnt=0;
	for(int i=1;i<x;i++)	cnt=max(cnt,f[i]&a[x]);
	return cnt;
}

int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)	s[i]=a[i];
		else
		{
			s[i]=s[i-1]&a[i];
		}
	}
	long long mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		f[i]=mx;
	}
	for(int i=2;i<=m;i++){
		for(int j=n;j>=i+1;j--){
			f[j]=chk(j);
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}*/
	//cout<<endl;
	cout<<f[n];
	return 0;
}
