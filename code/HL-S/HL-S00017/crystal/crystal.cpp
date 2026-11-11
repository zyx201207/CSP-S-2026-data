#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long INF=1e13;
const int N=5e5+5;
int n;
LL m,a[N],b[N];
LL maxx=-INF,minn=INF;
int ans=0;
bool f1=1,f2=1;
LL c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f1=false;
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=false;
		}
		minn=min(minn,a[i]);
		maxx=max(a[i],maxx);
	}
	if(f1==true){
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+i;
			if(c[i]>m) {
				cout<<i-1<<'\n';
				return 0;
			}
		}
		cout<<n<<'\n';
		return 0;
	}
	else if(f2==true){
		LL cha=a[2]-a[1];
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+i*cha;
			if(c[i]>m){
				cout<<i-1<<'\n';
				return 0;
			}
		}
		cout<<n<<'\n';
		return 0;
	}
	for(LL k=minn;k<=maxx;k++){
		LL w=m;
		int res=0,ed=-1;
		for(int i=1;i<=n;i++){
			b[i]=k-a[i];
			if(b[i]<0){
				ed=i-1;
				break;
			}
		}
		for(int i=ed;i>=1;i--){
			w-=b[i];
			if(w>=0) res++;
			else break;
		}
		ans=max(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}