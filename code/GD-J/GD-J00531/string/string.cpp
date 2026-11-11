#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,mid,siz,a[N],pre[N],sum1,sum2;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool cs=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i],pre[i]=pre[i-1]+a[i];
		if(a[i]!=1) cs=false; 
	}
	bool flag=true;
	if(mid%2==0) siz=mid,mid/=2,flag=false;
	else siz=mid,mid=mid/2+1;
	for(ll i=1;i<=n;i++){
		if(pre[i]<=mid){
			if(flag&&pre[i]==mid) continue;
			ll idx=lower_bound(pre+1,pre+n+1,siz-pre[i]+1)-pre;
			if(c[idx]!=c[i]){
				sum1+=a[i];
			}
		}else{
			ll idx=lower_bound(pre+1,pre+n+1,siz-pre[i]+1)-pre;
			if(c[idx]!=c[i]){
				sum2+=a[i];
			}
		}
	}
	cout<<min(sum1,sum2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

