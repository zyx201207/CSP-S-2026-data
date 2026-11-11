#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,a[2000005],n,d,ans=1e17,cnt,sum,f[3][2000005],ts,l=1;
map<string,int>m[2000005];
void step(int s,int st,string ss){
	if(s==ts){
		if(ans==st&&m[l][ss]==0){
			if(cnt>2)return;
			cnt++;
			m[l][ss]=1;
		}
		ans=min(st,ans);
	}
	for(int i=1;i<=d;i++){
		string t="";
		int tt=a[s+i];
		while(tt!=0){
			int ttt=tt%10;
			t+=ttt+'0';
			tt/=10;
		}
		if(f[1][s+i]==2){
			f[1][s+i]=1;
			string sss=ss+t;
			step(s+i,st+1,sss);
			f[1][s+i]=2;
		}else if(f[2][s+i]==2){
			f[2][s+i]=1;
			ss+=t;
			string sss=ss+t;
			step(s+i,st+1,sss);
			f[2][s+i]=2;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen(" subway.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)a[i]=0;
		ans=1e17;
		cnt=sum=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]>=0)f[1][a[i]]=2;
			else f[2][a[i]]=2;
		}
		for(int i=1;i<=n-1;i++){
			for(int j=2;j<=n;j++){
				if(a[j]-a[i]==1||a[j]-a[i]==d)continue;
				string t="";
				int tt=a[i];
				while(tt!=0){
					int ttt=tt%10;
					t+=ttt+'0';
					tt/=10;
				}
				ts=a[j];
				step(a[i],0,t);
				if(cnt==2)sum++;
			}
		}
		l++;
		cout<<sum;
	}
}
