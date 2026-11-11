/*#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans,a[N],cf[N];
signed main(){
	freopen("crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) cf[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++){
        int len=m;
		bool flag=true;
        for(int j=i,cnt=1;j<=n;j++,cnt++){
			len-=abs(cf[j]);//*cnt
			if(len<0){
				ans=max(ans,--cnt);
				flag=false;
				break;
			}
//			else if(len==0){
//				ans=max(ans,cnt);
//				flag=false;
//				break;
//			}
		}
		if(flag) ans=max(ans,n-i+1);
	}
	printf("%lld",ans);
	return 0;
}
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,m1,ans,ansx,cntx,a[N],pre_cf[N];
map<string,int> tg;
string cl(int x){
	string jg;
	while(x){
		int t=x%10;
		x/=10;
		jg=(char)(t+48)+jg;
	}
	return jg;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	m1=m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		tg[cl(a[i])]++;
		if(a[i]-a[i-1]==a[i-1]-a[i-2] && i-2>0) cntx++;
		ansx=max(ansx,tg[cl(a[i])]);
	} 
	sort(a+1,a+1+n);
	if(ansx==n){
		printf("%lld",n);
		return 0;
	}
	if(cntx==n-2){
		int num=a[n]-a[n-1],cnt1=1;
		while(m1-num*cnt1>=0){
			m1-=num*cnt1;
			cnt1++;
		}
		printf("%lld",cnt1);
		return 0;
	}
	for(int i=1;i<=n;i++) pre_cf[i]=pre_cf[i-1]+(a[i]-a[i-1])*(i-1);
	int head=1,tail=1;
	while(tail<=n){
		if(m-(pre_cf[tail]-pre_cf[head-1])>=0){
			tail++;
			continue;
		}
		else{
			ans=max(ans,tail-head);
			head++;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ansx,cntx,a[N],tg[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		tg[a[i]]++;
		if(a[i]-a[i-1]==a[i-1]-a[i-2] && i-2>0) cntx++;
		ansx=max(ans,tg[a[i]]);
	} 
	if(ansx==n){
		printf("%lld",n);
		return 0;
	} 
	if(cntx==n-2){
		int num=a[n]-a[n-1],cnt1=1;
		while(m-num*cnt1>=0){
			m-=num*cnt1;
			cnt1++;
		}
		printf("%lld",cnt1);
		return 0;
	}
	return 0;
}
*/
