#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500001],ans,s[500001],mid,L,R;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		L=1;
		R=i;
		while(L<R){
			mid=(L+R)/2;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m){
				R=mid;
			}
			else{
				L=mid+1;
			}
		}
		//cout<<a[i]<<":"<<i-R+1<<endl;
		ans=max(ans,i-R+1);
	//cout<<ans<<"<"<< i-R+1<<endl;
	}
	cout<<ans;
	return 0;
} 
