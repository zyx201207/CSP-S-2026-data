#include<bits/stdc++.h>
using namespace std;
int n,m,a[2050],imax=INT_MIN,b[35],c[2050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>imax) imax=a[i];
	}	
	if(m==1) 
	{
		cout<<imax;
		exit(0);
	}
	return 0;
}
