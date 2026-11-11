#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int MAX_N=2e5;
int n;
ll a[MAX_N+10],b[MAX_N+10];char c[MAX_N+10];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]=a[i]+a[i-1];
		b[i]=a[i-1]+1;
	}
	ll mid=a[n]/2,mid2=(a[n]+1)/2;
	for(int i=1,j=n;i<=n&&j>=1;){
		if(a[i]>mid||b[j]<mid2)break;
		if(a[i]-b[i]+1==0){
			i++;
			continue;
		}
		if(a[j]-b[j]+1==0){
			j--;
			continue;
		}
		ll tmp=min(a[i]-b[i]+1,a[j]-b[j]+1);
		if(c[i]!=c[j])ans+=tmp;
		b[i]+=tmp;a[j]-=tmp;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>mid&&b[i]<mid2){
			ans+=abs((a[i]-mid)-(mid2-b[i])-1);
			break;
		}
	}
	cout<<ans;
	return 0;
}
