#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,k,a[N];
ll sum[N];
ll ch[N];
ll d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		
	}sort(a+1,a+1+n);
	
	for(int i=2;i<=n;i++){
		d[i-1]=a[i]-a[i-1];
		sum[i-1]=sum[i-2]+1ll*d[i-1]*(i-1);
		ch[i-1]=ch[i-2]+d[i-1];
	}if(n>5000){
		for(int i=2;i<=n;i++){
			if(sum[i-1]>m){
				cout<<i-1;return 0;
			}
		}cout<<n;return 0;
	} 
	for(int len=2;len<=n;len++){
		bool f=0;
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			ll res=sum[j-1]-sum[i-1]-1ll*(i-1)*(ch[j-1]-ch[i-1]);
			if(len==2){
				res=d[j-1];
			}//cout<<res<<" "<<i<<" "<<j<<endl;
			if(res<=m){
				f=1;break;
			}
		}if(!f){
			cout<<len-1<<endl;return 0;
		}
	}cout<<n;return 0;
	return 0;
}
