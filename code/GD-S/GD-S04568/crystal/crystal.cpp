#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000005];
long long ans[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}long long ans[500050],b[500050];
	for(int i=n;i>=2;i--){
		long long bnt=i,cnt=m;
		while((cnt-(a[i]-a[bnt--]))){
			ans[i]++;
		}
	}
	cout<<ans;
	return 0;
}
