#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0,cnt=0;
	for(int k=30;k>=1;k--){
		cnt=0,ans=2147483647;
		for(int i=n;i>=0;i--){
			if(a[i]&(1<<k)){
				if(cnt<m){
					cnt++;
					ans&=a[i];
				}
			}
		}
		if(cnt==m){
			cout<<ans;
			break;
		}
	}
} 
