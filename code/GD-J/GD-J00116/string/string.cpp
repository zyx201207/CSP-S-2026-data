#include<bits/stdc++.h>
using namespace std;
#define int long long
#define itn int
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int ans=0;
	int cnt1=0,cnt2=0;
	for(int i=1,j=n;i<j&&cnt1+cnt2<=sum;){
		if(c[i]==c[j]){
			cnt1+=min(a[i],a[j]);
			cnt2+=min(a[i],a[j]);
		}else ans+=min(a[i],a[j]);
		if(a[i]<a[j]){
			a[j]-=a[i];	
			i++;
		}else if(a[i]>a[j]){
			a[i]-=a[j];	
			j--;
		}else{
			i++;
			j--;
		}
	}
	cout<<ans;
}
