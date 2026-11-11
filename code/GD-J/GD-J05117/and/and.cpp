#include<bits/stdc++.h>
using namespace std;
#define int_ long long
//#define frp(i,a,b) for(int_ (i)=(int_)(a);i<=(int_)(b);i++)
const int_ N=2e5+7,A=22;
int_ a[N];
int_ n,m;
map<int_,int_> mp;
int_ dp[1<<A];
//int_ vfp[A];
struct ac{
	int cnt,num;
}p[25000007];
int cp;
vector<ac> g;
unordered_map<int_,int_> mp2; 
int_ mx;
void s1(){
	int_ ans=0;
	for(int_ mask=1;mask<=(1<<n)-1;mask++){
		int_ t=mask,i=0,yh=(1<<n)-1,w=0;
		while(t){
			i++;
			if(t%2){
				w++;
				yh&=a[i];
			}
			t/=2;
		}
		if(w==m)
			ans=max(ans,yh);
	}
	cout<<ans;
	return ;
}
void s2(){
	cout<<a[n];
	return ;
}
void s3(){
	int_ ans=0;
	for(int_ i=1;i<=n;i++)
		for(int_ j=1;j<=n;j++)
			if(i!=j)
				ans=max(ans,a[i]&a[j]);
	cout<<ans;
	return ;
}
void s4(){
	int_ ans=a[1];
	for(int_ i=2;i<=n;i++)
		ans&=a[i];
	cout<<ans;
	return ;
}
void s5(){
	cout<<a[n-m+1];
	return ;
}
void s6(){
	for(int_ i=1;i<=n;i++){
		int_ mask=a[i];
		for(int_ t=mask;t;t=mask&(t-1)){
			dp[t]++;
		}
		dp[0]++;
	}
	for(int_ mask=mx;mask>=1;mask--){
		if(dp[mask]>=m){
			cout<<mask;
			break;
		}
	}
	return ;
}
void s7(){
	int ans=0;
	for(int_ i=1;i<=n;i++){
		int_ mask=a[i];
		for(int_ t=mask;t;t=mask&(t-1)){
			if(!mp2[t])
				mp2[t]=++cp,p[cp].cnt=1,p[cp].num=t;
			else
				p[mp2[t]].cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i].cnt>=m)
			ans=max(ans,p[i].num);
	}
	cout<<ans;
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int_ inf=0;
	for(int_ i=0;i<=30;i++){
		mp[(1<<i)-1]=1;
//		vfp[i]=pow(2,i);
	}
	for(int_ i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(!mp[a[i]])
			inf=1;
	}
	sort(a+1,a+1+n);
	if(n<=20){
		s1();
	}else if(m==1){
		s2();
	}else if(m==2 and n<=2000){
		s3();
	}else if(m==n){
		s4();
	}else if(!inf){
		s5();
	}else if(mx<=(1<<20)){
		s6();
	}else{
		s7();
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
