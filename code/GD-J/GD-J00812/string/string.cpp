#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			long long shu=min(a[l],a[r]);
			ans+=shu;
			a[l]-=shu,a[r]-=shu;
		}else{
			long long shu=min(a[l],a[r]);
			a[l]-=shu,a[r]-=shu;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
}
