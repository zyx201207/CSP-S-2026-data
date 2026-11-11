#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;
int a[N+10];
int n,m,sum=0;
void solvea(){
	int mid=n/2+1,cnt=0,ans=0;
	for(int i=1;cnt<m;i++){
		if(mid+i<=n)cnt+=i,ans++;
		if(mid-i>=1)cnt+=i,ans++;
	}
	cout<<ans+1;
}
void solveb(int dis){
	int ave=floor(1.0*ave/n),ave2=ceil(1.0*ave/n),mid=n/2+1,ans1=0,ans2=0;
	for(int i=0,cnt=0;cnt<m;i++){
		if(mid+i<=n&&cnt+abs(ave-a[mid+i])<m)cnt+=abs(ave-a[mid+i]),ans1++;
		if(mid-i>=1&&cnt+abs(ave-a[mid-i])<m)cnt+=abs(ave-a[mid-i]),ans1++;
	}
	if(ave!=ave2)for(int i=0,cnt=0;cnt<m;i++){
		if(mid+i<=n&&cnt+abs(ave2-a[mid+i])<m)cnt+=abs(ave2-a[mid+i]),ans2++;
		if(mid-i>=1&&cnt+abs(ave2-a[mid-i])<m)cnt+=abs(ave2-a[mid-i]),ans2++;
	}
	cout<<max(ans1,ans2)+1;
}
int b[N+10],maxcnt=0;
void solvec(int x=1,int cnt=0){
	if(x==n+1){
		if(cnt==0)return; 
		int sm=0;
		for(int i=1;i<=cnt;i++){
			sm+=b[i];
		}
		int ave1=floor(sm/x),ave2=ceil(sm/x);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=cnt;i++){
			cnt1+=abs(ave1-a[i]);
		}
		if(ave1!=ave2)for(int i=1;i<=cnt;i++){
			cnt2+=abs(ave2-a[i]);
		}else cnt2=INT_MAX;
		int acnt=min(cnt1,cnt2);
		if(acnt<=m){
			maxcnt=max(maxcnt,cnt);
		}
		return;
	}
	solvec(x+1,cnt);
	b[cnt]=a[x];
	solvec(x+1,cnt+1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	bool flaga=true,flagb=true,dis;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=i)flaga=false;
		if(i==2)dis=a[i]-a[i-1];
		else if(a[i]-a[i-1]!=dis)flagb=false;
	}
	if(flaga){
		solvea();
	}else if(flagb){
		solveb(dis);
	}else{
		solvec();
		cout<<maxcnt;
	}
	return 0;
}
