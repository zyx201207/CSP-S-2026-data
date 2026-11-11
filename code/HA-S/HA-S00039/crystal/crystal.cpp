#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
unordered_map<int,int>ma;	
int tepan1=1,tepan2=1;
int n,m,maxn=1;
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
		ma[a[i]]++;
	}
	sort(a+1,a+1+n);
	int cha=a[2]-a[1];
	if(a[1]!=1)tepan1=0;
	for(int i=2;i<=n;i++){		
		if(a[i]!=i){
			tepan1=0;
		}
		if(a[i]-a[i-1]!=cha)tepan2=0;
	}
	
	if(tepan1){
		for(int i=1;i<=n;i++){
			if(i*(i+1)>m*2){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(tepan2){
		for(int i=1;i<=n;i++){
			if(i*(cha+cha*i)>m*2){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(n<=5000){
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			int ans=0,cnt=0;
			for(int j=i-1;j>=1;j--){
				ans+=(a[i]-a[j]);
				if(ans>m)break;
				if(a[i]!=a[j])cnt++;
			}
			maxn=max(maxn,cnt+ma[a[i]]);	
		}
		cout<<min(maxn,n);
		return 0;
	}
	int u=lower_bound(a+1,a+1+n,a[n]/2)-a;
	for(int i=u-1000;i<=u+1000;i++){
		int ans=0,cnt=0;
		for(int j=i-1;j>=1;j--){
			ans+=(a[i]-a[j]);
			if(ans>m)break;
			if(a[i]!=a[j])cnt++;
		}
		maxn=max(maxn,cnt+ma[a[i]]);	
	}
	cout<<min(maxn,n);
	return 0;
}
//80pts