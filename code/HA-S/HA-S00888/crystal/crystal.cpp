#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5,inf = 4e18;
int a[N],s[N],n,m;
inline read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
bool check(int x){
	int minn = inf;
	for(int l = 1;l<=n-x+1;l++){
		int r=l+x-1;
		minn=min(minn,x*a[r]-(s[r]-s[l-1]));
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l = 0,r=n+1;
	while(l<r){
		int mid = (l+r+1)/2;
		//cout << mid << " ";
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout << l;
	return 0;
}
