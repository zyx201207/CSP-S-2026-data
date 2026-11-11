#include<bits/stdc++.h>
using namespace std;
long long n,m,a[700000],x=1e18,y=-1e18,w,s,g;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x=min(x,a[i]);
		y=max(y,a[i]);
	}
	sort(a,a+n);
	for(int i=x;i<=y;i++){
		g=w=0;
		for(int j=n-1;j>=0;j--){
			if(a[j]<=i){
				if(w+i-a[j]>m)break;
				w+=i-a[j];
				g++;
			}
		}
		if(s<g){
			s=g;
		}
	}
	cout<<s;
	return 0;
} 
