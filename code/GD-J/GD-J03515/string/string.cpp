#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){//200000
		cin>>a[i]>>c[i];
	}
	unsigned long long ans=0;
	int l=1,r=n;
	while(l<r){
		int mi=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=mi;
		}
		a[l]-=mi;
		a[r]-=mi;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
