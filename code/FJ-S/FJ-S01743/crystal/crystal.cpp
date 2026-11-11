#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500005],ans=0;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		int u=m;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]<=u){
				u-=(a[i]-a[j]);
			}
			else{
				if(ans<(i-j)){ans=i-j;}
				break;
			}
			if(j==0&&ans<i+1){ans=i+1;}
		}
	}
	cout<<ans;
	return 0; 
} 
