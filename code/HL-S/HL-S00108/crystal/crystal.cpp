#include<bits/stdc++.h>

using namespace std;

long long a[100005];
long long n,m,k,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			m=m-(a[i]-a[j]);
			if(m<0){
				break;
			}
			a[j]=a[i];
		}
		if(m<=0){
			break;
		}
	}
	k=a[1];
	for(long long i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
