#include<bits/stdc++.h>
using namespace std;
typedef int intt;
#define int long long
const int maxn=5e5+10;
int n,m,a[maxn],ans,cnt,sum;
struct node{int x,tot;}b[105];
bool check(){
	int tmp=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=tmp)return 0;
	}
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1); 
	if(check()){
		for(int i=n-1;i>=1;i--){
			if(a[n]-a[i]<=m)m-=(a[n]-a[i]),ans++;
		}
		cout<<ans+1;exit(0);
	}
	else if(n<=5000){
		for(int i=1;i<=n;i++){
			int tmp=0,mm=m;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=mm)mm-=(a[i]-a[j]),tmp++;
			}
			ans=max(ans,tmp);
		}
		cout<<ans+1;exit(0);
	} 
	else if(a[n]<=100){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1])b[++cnt]={a[i],1};
			else b[cnt].tot++;
		}
		for(int i=1;i<=cnt;i++){
			int tmp=b[i].tot,mm=m;
			for(int j=i-1;j>=1;j--){
				if((b[i].x-b[j].x)*b[j].tot<=mm)mm-=(b[i].x-b[j].x)*b[j].tot,tmp+=b[j].tot;
				else{tmp+=mm/(b[i].x-b[j].x);break;}
			}
			ans=max(ans,tmp);
		}
		cout<<ans;exit(0);
	}
	else{
		int j=1;
		for(int i=2;i<=n;i++){
			sum+=(i-j)*(a[i]-a[i-1]);
			while(sum>m)sum-=(a[i]-a[j]),j++;
			ans=max(ans,i-j+1);
		}
		cout<<ans;
	}
	return 0;
} 


/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

10 20
1 2 3 4 5 6 7 8 9 10
*/



