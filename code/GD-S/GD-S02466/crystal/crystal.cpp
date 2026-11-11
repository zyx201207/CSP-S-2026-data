#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,z,mx=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n); 
	for(long long i=1;i<n;i++){
		if(a[i]==a[i+1])continue;
		long long al=1,x=i-1;z=m;
		while(z>=a[i]-a[x]&&x>=0){
			z-=a[i]-a[x];
			al++;
			x--;
		}
		if(al>mx){
			mx=al;
		}
	}
	cout<<mx;
	return 0;
}


