#include<iostream>
using namespace std;
const int N=2e5+5;
long long cnt[N];
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		cnt[i]=cnt[i-1]+x;
		cin>>a[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(cnt[l]<=cnt[n]/2){
		while(cnt[r-1]>cnt[n]-cnt[l-1])r--;
		while(cnt[r]>=cnt[n]+1-cnt[l]){
			if(a[l]!=a[r])ans+=min(cnt[n]-cnt[l-1],cnt[r])-max(cnt[n]-cnt[l],cnt[r-1]);
			r--;
		}
		r++;
		l++;
	}
	if(cnt[l-1]<cnt[n]/2){
		while(cnt[r-1]>cnt[n]-cnt[l-1])r--;
		while(cnt[r]>=cnt[n]+1-cnt[n]/2){
			if(a[l]!=a[r])ans+=min(cnt[n]-cnt[l-1],cnt[r])-max(cnt[n]-cnt[n]/2,cnt[r-1]);
			r--;
		}
	}
	cout<<ans;
	return 0;
}
