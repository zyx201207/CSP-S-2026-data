#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2*1e5;
int n,a[MAXN+5];
int ans=0;
char c[MAXN+1];
int l[MAXN+5],r[MAXN+5];
int len=0;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l[i]=len+1;
		len+=a[i];
		r[i]=len;
	}
	
	int lt=1,rt=n;
	while(r[lt]<l[rt]){
		if(c[lt]==c[rt]){
			if(a[lt]<a[rt]){
				a[rt]-=a[lt];
				r[rt]-=a[lt];
				lt++;
			}
			else if(a[lt]>a[rt]){
				a[lt]-=a[rt];
				l[lt]+=a[rt];
				rt--;
			}
			else if(a[lt]==a[rt]){
				lt++;
				rt--;
			}
		}
		else{
			if(a[lt]<a[rt]){
				ans+=a[lt];
				a[rt]-=a[lt];
				r[rt]-=a[lt];
				lt++;
			}
			else if(a[lt]>a[rt]){
				ans+=a[rt];
				a[lt]-=a[rt];
				l[lt]+=a[rt];
				rt--;
			}
			else if(a[lt]==a[rt]){
				ans+=a[lt];
				lt++;
				rt--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
