#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int a[maxn];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
		int ans=0;
		for(int i=1;i<=(1<<n);i++){
			int k=i,cnt=0,j=0;
			int res=(1<<20)-1;
			while(k){
				if(k&1){
					cnt++;
					res&=a[j];
				}
				k>>=1;
				j++;
			}
			if(cnt!=m) continue;
			ans=max(res,ans);
		}
		cout<<ans;
	}else if(m==n){
		int res=a[0];
		for(int i=0;i<n;i++) res&=a[i];
		cout<<res;
	}else{
		sort(a,a+n);
		cout<<a[n-m];
	}
	return 0;
} 
