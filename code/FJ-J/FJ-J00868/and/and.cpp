#include<bits/stdc++.h>
using namespace std;
long long n,m,a[204800],i,j,f[204800],s0,s1=0,maxx=-1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(i==0)s0=a[i];
		else s0&=a[i];
	}
	if(m==n){
		cout<<s0;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	maxx=-1;
	if(m==2){
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		long long tg=0;
		maxx=-1;
		for(int i=0;i<n;i++){
			s1=a[0];
			for(int i=1;i<n;i++){
				if(i==tg)i++;
				if(i>=n)break;
				s1&=a[i];
			}
			maxx=max(maxx,s1);
			tg++;
		}
		cout<<maxx;
		return 0;
	}
	cout<<0;
	
	return 0;
} 
