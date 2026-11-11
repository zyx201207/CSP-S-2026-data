#include<bits/stdc++.h>
using namespace std;
long long typedef ll;
ll n,sum,cnt,tnt,temp;
bool bo=true,boo=true;
ll a[200005],b[200005],e[200005];
char c[200005],d[200005],f[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2==1)boo=false;
	sum/=2;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		if(cnt>sum&&bo){
			bo=false;temp=i;
			break;
		}
	}
	cnt=0;
	bo=true;
	for(int i=1;i<=temp;i++){
		if(cnt+a[i]<=sum){
			cnt+=a[i];
			b[i]=a[i];
			d[i]=c[i];
		}else{
			b[i]=sum-cnt;
			d[i]=c[i];
			bo=false;
			tnt=b[i];
		}
	}
	if(bo&&!boo)b[temp]--;
	for(int i=temp;i<=n;i++){
		if(!bo){
			e[temp]=a[temp]-tnt;
			f[temp]=c[temp];
			bo=true;
			if(!boo)e[temp]--;
			continue;
		}
		e[i]=a[i];
		f[i]=c[i];
	}
	ll lt=1,rt=n,ans=0;
	while(lt<rt){
		if(d[lt]!=f[rt]){
			if(b[lt]>e[rt]){
				ans+=e[rt];
				b[lt]-=e[rt];
				rt--;
			}else if(b[lt]<e[rt]){
				ans+=b[lt];
				e[rt]-=b[lt];
				lt++;
			}else{
				ans+=b[lt];
				rt--;
				lt++;
			}
		}else{
			if(b[lt]>e[rt]){
				b[lt]-=e[rt];
				rt--;
			}else if(b[lt]<e[rt]){
				e[rt]-=b[lt];
				lt++; 
			}else{
				lt++;
				rt--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
