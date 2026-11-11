#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long k;
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(m!=0){
		k=1;
		for(int i=1;i<n;i++){
			if(a[i]!=a[i+1]){
				break;
			}else{
				k++;
			}
		}
		for(int i=1;i<=k;i++){
			a[i]++;
		}
		m-=k;
	}
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
} 
