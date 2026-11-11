#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],c[N],s[N],sum,ans;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	bool flagA=1;
	cin >> n;
	for(int i=1;i<=n;i++){
		char cc;
		cin >> a[i] >> cc;
		c[i]=int(cc-'a')+1;
//		if(a[i]>50)flagA=0;
	}
//	if(flagA){
//		for(int i=1;i<=n;i++){
//			for(int j=sum+1;j<=sum+a[i];j++){
//				s[j]=c[i];
//			}
//			sum+=a[i];
//		}
//		for(int i=1;i<=sum/2;i++){
//			if(s[i]!=s[sum+1-i])ans++;
//		}
//		cout<<ans;
//	}else{
		int l=1,r=n;
		while(l<r){
			if(c[l]!=c[r])ans+=min(a[l],a[r]);
			if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else{
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
		}
		cout<<ans;
//	}
	return 0;
}
