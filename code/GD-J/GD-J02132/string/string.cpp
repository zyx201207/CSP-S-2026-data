#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define int long long
const int N=2e5+10;
int n,a[N],ans,now1,now2,sum[N],res1,res2;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	REP(i,1,n) cin>>a[i]>>c[i],sum[i]=sum[i-1]+a[i];
	now1=1,now2=sum[n],res1=a[1],res2=a[n];
	for(int i=1,j=n;now1<now2&&i<j;){
		if(res1>res2){
			if(c[i]==c[j]) res1-=res2,now1+=res2,now2-=res2,j--,res2=a[j];
			else res1-=res2,ans+=res2,now1+=res2,now2-=res2,j--,res2=a[j];
		}
		else{
			if(c[i]==c[j]) res2-=res1,now1+=res1,now2-=res1,i++,res1=a[i];
			else res2-=res1,ans+=res1,now1+=res1,now2-=res1,i++,res1=a[i];
			if(res2==0) j--,res2=a[j];
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
