#include<bits/stdc++.h>
#define mk mkae_pair
#define fir first
#define sec second
using namespace std;

inline int read(){char ch=getchar();int xxx=0,yyy=1;
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=500005;

int n;
ll m;
ll a[maxn],sum[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
		int l=1,r=i,mid;
		while(l<=r){
			mid=l+r>>1;
			if(-(sum[i]-sum[mid-1])+a[i]*(i-mid+1)<=m){
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-(r+1)+1);
	}
	cout<<ans<<endl;
	return 0;
}
