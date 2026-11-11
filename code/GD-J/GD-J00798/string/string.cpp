#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
constexpr int N=2e5+10;
ll a[N];
char c[N];
int n;
ll sum;
vector<pair<int,char>>v;
void brute(){
	string s;
	s+=' ';
	for(int i=0;i<n;++i){
		for(int j=0;j<v[i].fi;++j){
			s+=v[i].se;
		}
	}
	int i,j;
	if(sum&1) i=j=sum/2+1;
	else i=sum/2,j=i+1;
	ll ans=0;
	while(i>=1 and j<=sum){
		if(s[i]!=s[j]) ++ans;
		--i,++j;
	}
	cout<<ans;
}
void solve(){
	cin>>n;
	if(n==1){
		cout<<0;
		return;
	}
	for(int i=0;i<n;++i){
		int x;
		char c;
		cin>>x>>c;
		v.push_back({x,c});
	}
	for(int i=0;i<n;++i) sum+=v[i].fi;
	if(sum<=1e8){
		brute();
		return;
	}
	ll temp=sum/2+1;
	bool x=(sum&1); 
	int cnt=1;
	a[1]=v[0].fi,c[1]=v[0].se;
	if(!x and a[1]>=temp) ++a[1],x=1;
	else if(!x) temp-=a[1];
	for(int i=1;i<n;++i){//combine
		if(v[i].se==v[i-1].se) a[cnt]+=v[i].fi;
		else{
			++cnt;
			a[cnt]=v[i].fi,c[cnt]=v[i].se;
		}
		if(!x and a[cnt]>=temp) ++a[cnt],x=1;
		else if(!x) temp-=a[cnt];
	}
	ll ans=0;
//	if(sum&1){
	temp=sum/2+1;//找第mid个字符 
	int k=1;//第mid个字符所在块 
	while(temp-a[k]>0) temp-=a[k],++k;
	ll mid=temp;
	ll l=mid-1,r=a[k]-mid,lstlen=0;
	lstlen=abs(l-r),ans+=lstlen;
	int i=k,j=k;
	int flag=0;//1:和左边 2:和右边  
	if(l<r) --i,flag=1;
	else if(l>r) ++j,flag=2;
	else --i,++j; 
	while(i>=1 and j<=n){
		if(flag==1){
			if(a[i]<=lstlen) lstlen-=a[i],--i;
			else a[i]-=lstlen,flag=0;
		}
		else if(flag==2){
			if(a[j]<=lstlen) lstlen-=a[j],++j;
			else a[j]-=lstlen,flag=0;
		}
		else{
			lstlen=abs(a[j]-a[i]),ans+=lstlen;
			if(a[j]<a[i]) ++j;
			else if(a[i]<a[j]) --i;
			else ++i,--j;
		}
	}
//	}
//	else{
//		ll temp=sum/2;
//		int k=1;
//		while(temp-a[k]>0) temp-=a[k],++k;
//		ll mid1=temp,mid2=temp+1;//左 
//	}
	cout<<ans;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
}
/*
3
2 a
2 b
1 c
2

2
2 a
3 a
0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
3000000000
*/
