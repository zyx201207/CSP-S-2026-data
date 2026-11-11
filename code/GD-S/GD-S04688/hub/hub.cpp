#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	
	
	for(int i=1;i<=t;i++){
	
		long long n,k,a[100086],b[100086],mx=0,mn=100086;
		cin>>n>>k;
		
		for(int j=1;j<=n-1;j++){
			cin>>a[i]>>b[i]; 
		}
		cout<<a[1]-b[2];
	}
	
} 
