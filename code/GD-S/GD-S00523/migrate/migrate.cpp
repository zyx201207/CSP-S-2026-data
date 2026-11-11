#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50,mod=1e9+7;
int n;
long long a[N],d;
int l[N],r[N];
int f[N];
int ans=0;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],l[i]=r[i]=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&a[i]-a[j]>d)r[j]=i-1,++j;
		l[i]=j;
		if(i==n)while(j<=i)r[j++]=i;
	}
//	for(int i=1;i<=n;i++){
//		cout<<l[i]<<" "<<r[i]<<"\n";
//	}
	for(int i=1;i<=n;i++)f[i]=0;
	for(int i=1;i<=n;i++){
		int R=r[i];
		for(int j=i+1;j<=n;j++){
			f[j]=0;
			if(a[j]-a[i]<=d)f[j]=1;
			else{
				while(l[j]>R&&R!=n){
					if(R==r[R])break;
					R=r[R];
				}
				if(R==r[R])break;
				f[j]+=f[R]-f[l[j]-1];
//				for(int k=l[j];k<=R;++k){
//					f[j]+=f[k];
//				}
			}
			if(f[j]==2)++ans;
			f[j]+=f[j-1]; 
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			cout<<i<<"->"<<j<<": "<<f[i][j]<<"\n";
//			cout<<f[i][j]<<" ";
//			if(f[i][j]==2)++ans;
//		}
//		cout<<'\n';
//	}
	cout<<ans<<'\n'; 
}
void solve2(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],l[i]=r[i]=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&a[i]-a[j]>d)r[j]=i-1,++j;
		l[i]=j;
		if(i==n)while(j<=i)r[j++]=i;
	}
	int xl=l[n],xr=r[1];
	if(xr-xl>1){
		cout<<0<<"\n";
		return ;
	}
	if(xr-xl==1){
		int cntl=1,posl=1,cntr=1,posr=n;
		while(r[posl+1]==r[posl])++posl,++cntl;
		while(l[posr-1]==l[posr])--posr,++cntr;
		cout<<cntl*cntr<<"\n"; 
		return ;
	}
	if(xr==xl){
		int cntl=1,posl=1,cntr=1,posr=n;
		while(r[posl+1]==r[posl])++posl,++cntl;
		while(l[posr-1]==l[posr])--posr,++cntr;
		for(int i=posl+1;i<=n;i++){
			if(r[i]-l[n]==2)ans+=cntr;
			else break; 
		}
		for(int i=posr-1;i>=1;i--){
			if(r[1]-l[i]==2)ans+=cntl;
			else break;
		}
		cout<<ans<<"\n";
		return ;
	}
}
void solve3(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],l[i]=r[i]=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&a[i]-a[j]>d)r[j]=i-1,++j;
		l[i]=j;
		if(i==n)while(j<=i)r[j++]=i;
	}
	int gd=r[1]-1;
	if(gd<=1){
		cout<<"0\n";
		return ;
	}
	for(int i=gd+gd;i<=n;i++){
		++ans;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--){
		if(c==13||c==14)solve2();
		else if(c==11||c==12)solve3(); 
		else solve();
	} 
	return 0;
}
/*
如果一个点跳到x步跳到的最远点有i条路径，那么这个点跳>x步跳到的点路径数不会小于i
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
