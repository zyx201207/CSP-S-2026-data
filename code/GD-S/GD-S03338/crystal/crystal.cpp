#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,s[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&s[i]);
	sort(s+1,s+n+1);
	if(n<=5000||m<=1e8){
		for(int i=1;i<=n;i++){
			if(s[i]==s[i-1]&&s[i+1]==s[i])continue;
			long long zong=0,anss=0;
			for(int j=i;j>=1;j--){
				zong+=s[i]-s[j];
				if(zong>m)break;
				else anss++;
			}
			if(ans<anss)ans=anss;
		}
		printf("%lld",ans);
	}
	else if(m>1e8){
		long long js=s[2]-s[1],zong=0,anss=0;
		for(int i=n;i>=1;i--){
			zong+=anss*js;
			if(zong>m)break;
			else anss++;
		}
		if(ans<anss)ans=anss;
		printf("%lld",ans);
	}
	return 0;
}
