#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
		return;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
int c,T,n,d,a[N],ans;
vector<pair<int,int> >v;
void solve(int l,int r){
	v.clear();
	for(int i=l;i<=r;i++){
		int pos1=upper_bound(a+l,a+r+1,a[i]+d)-a-1;//左边向右最后一个点 
		int pos2=pos1-1; 
		int j=upper_bound(a+l,a+r+1,a[pos2]+d)-a-1;
		if(j-i+1<4||a[j]-a[i]<=d)continue;
		if(pos2!=lower_bound(a+l,a+r+1,a[j]-d)-a){continue;}
		v.push_back(make_pair(i,j));
//		cout<<i<<' '<<j<<'\n';
//		cout<<a[j]<<' '<<a[lower_bound(a+i,a+r+1,a[j]-d)-a]<<' '<<pos2<<'\n';
	}
	for(int i=0;i<v.size();i++){
		if(i==0&&i==v.size()-1){
			ans+=(r-v[0].second+1)*(v[0].first-l+1);
		}
		else if(i==0){
			ans+=(v[1].second-v[0].second)*(v[0].first-l+1);
		}
		else if(i==v.size()-1){
			ans+=(v[i].first-v[i-1].first)*(r-v[i].second+1);
		}
		else{
			ans+=(v[i].first-v[i-1].first)*(v[i+1].second-v[i].second);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[n+1]=4000000000000000000;
		int lst=1;
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]>d){
				solve(lst,i);
				lst=i+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
6 3
0 1 2 3 4 7
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

*/ 

