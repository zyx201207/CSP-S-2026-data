#include<iostream>
#include<algorithm> 
using namespace std;
typedef long long ll;
const int N = 500005;

ll read(){
	ll k = 0,f=1;char c = getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())k=(k<<1LL)+(k<<3LL)+(c^48);
	return k*f;
}

ll n,m;
ll a[N],S[N];

bool check(int k,int i){
	return S[k]-k*a[i]-S[i]<=m-i*a[i];
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i = 1;i<=n;i++)a[i] = read();
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++)S[i] = S[i-1]+a[i];
	int ans = 1;
	for(int i = 1;i<=n;i++){
		int l = 0,r = i,ret = 0;
		while(l<=r){
			int mid = (l+r)>>1; 
			if(check(mid,i)){
				r=mid-1;
				ret = mid; 
			}else{
				l=mid+1;
			}
		}
		ans = max(ans,i-ret);
	}
	printf("%d",ans); 
}
