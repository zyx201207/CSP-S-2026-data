#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s,ans;
bool comp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		cout<<0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,comp);
	for(int i=0;i<n;i++){
		s=a[i+1]-a[i];
		if(s>m){
			continue;
		}
		if(s<=m){
			if(ans<2){
				ans=2;
			}
		}
		for(int j=i+2;j<n;j++){
			s+=(a[j]-a[j-1])*(j-i);
			if(s>m){
				continue;
			}
			if(s<=m){
				if(ans<s){
					ans=j-i+1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
