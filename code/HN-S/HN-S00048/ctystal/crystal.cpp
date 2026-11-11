#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long cha[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i-1;j>=0;j--){
			cha[i]+=a[i]-a[j];
		}
	}
	long long ans=0;
	for(long long i=0;i<n;i++){
		if(cha[i]==m){
			ans=i;
			if(cha[i-1]=-cha[i]){
				for(long long j=i;j<n;j++){
					if(a[i]==a[j]){
						ans++;
					}
					else{
						break;
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}

