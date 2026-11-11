#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[510000];
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	for(int i=0;i<n;i++){
		int t=m;
		for(int j=0;j<n;j++){
			if(a[j]>sum){
				a[j]--;
				t--;
				if(a[j]==sum||t<0){
					break;
				}
			}
			else if(a[j]<sum){
				a[j]++;
				t--;
				if(a[j]==sum||t<0){
					break;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]==sum){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
