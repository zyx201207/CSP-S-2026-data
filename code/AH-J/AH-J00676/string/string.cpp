#include<bits/stdc++.h>
using namespace std;
long long sum,a[200005],n;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],&s[i]);
	}
	int l=1,r=n;
	while(l<r){
		if(s[l]!=s[r])sum+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else{
			a[r]-=a[l];
			l++;
		}
	}
	cout<<sum;
	return 0;
}
