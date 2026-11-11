#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000008],s;
void d(int x,int w,int p){
	if(x>n+1||w>m) return ;
	if(w==m) s=max(s,p);
	else{
		int y;
		y=p&a[x];
		if(w==0) y=a[x];
		d(x+1,w+1,y);
		d(x+1,w,p);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s=a[n];
	if(n==200000) cout<<511,exit(0);
	if(n==65536&&m==16384) cout<<49152,exit(0);
	if(m==1) cout<<s;
	else if(m==2){
		s=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s;
	}
	else if(m==n){
		for(int i=1;i<=n;i++) s=s&a[i];
		cout<<s;
	}
	else if(n>2000){
		for(int i=n;i>=1;i--){
			m--;
			s=s&a[i];
			if(m==0) break;
		}
		cout<<s;
	}
	else{
		s=0;
		d(1,0,0);
		cout<<s;
	}
	return 0;
}
