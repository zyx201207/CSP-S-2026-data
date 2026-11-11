#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long b[n];
	b[0]=0;
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long s=0,ss=0,maxx;
	for(int i=0;i<n;i++){
		if(s+b[i]<=m){
			if(ss!=0){
				s+=b[i];
			}
			ss++;
		}
		else{
			if(ss==i+1){
				maxx=ss;
			}
			else{
				maxx=max(maxx,ss);
			}
			s=0;
			ss=1;
		}
	}
	maxx=max(maxx,ss);
	cout<<maxx;
	return 0;
}

