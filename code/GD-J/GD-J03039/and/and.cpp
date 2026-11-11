#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m,a[100005],ans=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	if(m==2){
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
				if(a[i]&a[j]>ans)ans=a[i]^a[j];
			}
		}
	}cout<<ans;
	return 0;
}
