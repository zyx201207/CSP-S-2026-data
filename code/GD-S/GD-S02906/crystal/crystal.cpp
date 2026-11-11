#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	ll a[100000]={0};
	ll zong=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--){
		int o=1;
		int y=m;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]<=y){
				o++;
				y-=a[i]-a[j];
			}else{
				break;
			}
		}
		if(o>zong) zong=o;
		//cout<<o<<" ";
	}
	cout<<zong;
	
	
	
	return 0;
} 
