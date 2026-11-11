#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[500010],b[500010],d[100010],ans=-1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	int ok=1,ok1=1,ok2=1;
	long long mi=1e13,mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mi=min(mi,a[i]);
		mx=max(mx,a[i]);
		if(mx>100)ok2=0;
	}
	long long c=a[2]-a[1],c2=a[1];
	for(int i=1;i<=n;i++)if(a[i]!=c2){
		ok=0;break;
	}
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			ok1=0;	break;
		}
	}
	if(ok==1){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	if(ok1==1){
		long long cnt=0;
		for(int i=n-1;i>=1;i--){
			cnt+=a[n]-a[i];
			if(cnt>m){
				printf("%d",n-i+1);
				return 0;
			}
		}
		printf("%d",n);		
	}
	else if(ok2==1){
		for(int i=mi;i<=100;i++){
			for(int j=1;j<=n;j++){
				b[j]=abs(a[j]-i);
			}
			sort(b+1,b+n+1);
			long long cnt=0;
			for(int j=1;j<=n;j++){
				cnt+=b[j];
				if(cnt>m){
					ans=max(ans,1LL*j-1);
					break;
				}
			}
		}
		printf("%lld",ans);
	}
	else if(m==0){
		long long ac=-1;
		for(int i=1;i<=n;i++){
			d[a[i]]++;ac=max(ac,d[a[i]]);
		}
		printf("%lld",ac);
	}
	return 0;
}
