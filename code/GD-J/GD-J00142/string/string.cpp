#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define PII pair<ll,ll>
#define pb push_back
using namespace std;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
ll n,a[N],l=1,r,ans; 
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	ll cntl=a[l],cntr=a[r];
	while(l<r){
		if(cntl>cntr){
			if(c[l]!=c[r])ans+=cntr;
			cntl-=cntr;
			r--;
			cntr=a[r];
		}else if(cntl<cntr){
			if(c[l]!=c[r])ans+=cntl;
			cntr-=cntl;
			l++;
			cntl=a[l];
		}else{
			if(c[l]!=c[r])ans+=cntl;
			l++;
			r--;
			cntl=a[l],cntr=a[r];
		}
	}
	cout<<ans;
	return 0;
}
//aaabbbccc
