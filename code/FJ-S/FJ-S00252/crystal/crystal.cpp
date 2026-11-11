//T1 能量水晶(暴力） 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5*1e5+5;
bool flagB=true;
ll n,m1;
int maxnn=-1;
ll a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cha=a[2]-a[1];
	for(int i=2;i<=n;++i){
		if(a[i]-a[i-1]!=cha) flagB=false;
	}
	if(flagB==true){
		//cout<<"\nflagb\n";
		for(int i=1;i<=n;++i){
			if(((1+(i-1))*(i-1)/2)*cha<=m1) maxnn=i;
			else break;
		}
		cout<<maxnn<<endl;
		return 0;
	}
	int c;
	for(int i=1;i<=n;++i){
		int m=m1,ans=0;
		for(int j=i;j>=1;--j){
			int v=a[i]-a[j];
			if(m>=v) ans++,m-=v;
			else j=-1;
		}
		c=i-ans+1,maxnn=max(ans,maxnn);
	}
	cout<<maxnn<<endl;
	return 0;
}
/*//T1 能量水晶(暴力二分） 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5*1e5+5;
bool flagB=true;
ll n,m;
int maxnn=-1;
ll a[MAXN],s[MAXN];
int main(){
	freopen("shujuju.out","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll cha1=a[2]-a[1];
	for(ll i=2;i<=n;++i){
		if(a[i]-a[i-1]!=cha1) flagB=false;
	}
	if(flagB==true){
		//cout<<"\nflagb\n";
		for(ll i=1;i<=n;++i){
			if(((1+(i-1))*(i-1)/2)*cha1<=m) maxnn=i;
			else break;
		}
		cout<<maxnn<<endl;
		return 0;
	}
	s[0]=0;
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];//前缀和 
	}
	int c;
	for(int i=1;i<=n;++i){
		int l=1,r=i,mid=l+(r-l)/2;
		while(r>=l){
			mid=l+(r-l)/2;
			int cha=a[i]*(mid)-(s[i]-s[i-mid]);
			//cout<<endl<<cha<<" "<<mid<<" ";
			if(cha<=m) l=mid+1;
			else if(cha>m)r=mid-1;
		}
		if(maxnn<mid) maxnn=max(maxnn,mid),c=i;
		
	}
	//cout<<endl<<c<<endl;
	cout<<maxnn<<endl;
	return 0;
}*/
