#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005],s[500005];

bool check(int x,int lent,int L){
	int tmpte=lent*a[L]-s[L]+s[x-1];
	
	return tmpte<=m;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	if(n==1){
		int A;
		cin>>A;
		
		cout<<1;
		return 0;
	}
	
	bool ok=1;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	sort(a+1,a+n+1);
		
	int difff=a[2]-a[1];
	
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=difff) ok=0;
		
	if(ok){
		int tmp=0,ii=1;
		
		while(tmp<=m && ii<=n)
			tmp+=a[++ii]-a[1];
		
		cout<<ii-1;
		
		return 0;
	}
	
	for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
			
	if(n<=8000){
		
		for(int len=n;len>=1;len--){
			for(int i=1;i<=n-len+1;i++){
				int j=i+len-1;
				
				int tmpt=len*a[j]-s[j]+s[i-1];
				
				if(tmpt<=m){
					cout<<len;
					return 0;
				}
			}
			
		}
	}

	int maxn=1;

	for(int i=n;i>=1;i--){
		
		int l=0,r=n+1;
		while(l+1<r){
			int mid=(l+r) >> 1;
			
			if(check(mid,i-mid+1,i)) r=mid;
			else l=mid;
		}
		
		maxn=max(maxn,i-l);
	}

	cout<<maxn;
	return 0;
}
