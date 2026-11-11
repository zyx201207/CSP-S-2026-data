#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n;
long long int sum=0;
long long int ans=0;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		sum+=a[i];
	}
	int l=1,r=n;
	while(l<n){
		if(c[l]!=c[r]&&sum%2!=0){
			ans+=max(a[l],a[r]);
		}
		if(c[l]!=c[r]&&sum%2==0){
			ans+=min(a[l],a[r]);
		}
		l++,r--;
	}
	cout << ans;
	return 0;
}
