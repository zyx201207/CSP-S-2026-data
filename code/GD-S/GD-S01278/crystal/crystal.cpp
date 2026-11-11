#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	int inv[n]={};
	
	for(int i=0;i<n;i++){
		cin>>inv[i];
	}
	
	sort(inv,inv+n);
	
	int num = inv[n/2];
	
	int t=n/2;
	while(t>=0 and m>0){
		if(inv[t]<num){
			inv[t]++;
			m--;
		}
		if(inv[t]==num){
			t--;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		if(inv[i]==num)ans++;
	}
	
	cout<<ans;
	
	return 0;
} 
