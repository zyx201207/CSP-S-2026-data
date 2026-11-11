#include<bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
const int inf = 1e18;
int n,m,now,cnt,cur,ans,cha;
int a[N],num[250],tot,toa[250];
bool flagA=1,flagB=1,flag100=1;
inline int ABS(int x){
	return (x>0?x:-x);
}
inline int MAX(int a,int b){
	if(a>b) return a;
	return b;
}
void solve_min(){
	for(int i=1;i<=n;i++){
		now=a[i],cnt=0,cur=m;
		for(int j=i;j>=1;j--){
			if(now-a[j]<=cur){
				cur-=(now-a[j]);
				cnt++;
			}else break;
		}
		ans=MAX(ans,cnt);
	}
}
void solve_A(){
	int sum=0;ans=0;
	for(int i=1;i<=n;i++){
		if(m>=sum){
			sum+=a[i];
			ans++;
		}else break;
	}
}
void solve_B(){
//	cout<<"B\n";
	int sum=0;ans=0;
	for(int i=1;i<=n;i++){
		if(m>=sum){
			ans++;
			sum+=cha*ans;
		}else break;
	}
}
void solve_100(){
//	cout<<"S100\n";
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) tot++;
		num[tot]++;
		toa[tot]=a[i];
	}
//	for(int i=1;i<=tot;i++) cout<<toa[i]<<"->"<<num[i]<<"ge\n";
	for(int i=1;i<=tot;i++){
		now=toa[i],cnt=num[i],cur=m;
		for(int j=i-1;j>=1;j--){
			int cur1=toa[j],cur2=num[j];
			if(cur>=(now-cur1)*cur2){
				cur-=(now-cur1)*cur2;
				cnt+=cur2;
			}else{
				while(cur>=(now-cur1)){
					cur-=now-cur1;
					cnt++;
				}	
				break;
			}
		}
		ans=MAX(ans,cnt); 
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int cur1=0;cha=inf;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ABS(a[i])>100) flag100=0;
		if(a[i]!=i) flagA=0;
		if(i!=1&&flagB){
			cur1=a[i]-a[i-1];
			if(cha==inf) cha=cur1;
			if(cha!=cur1) flagB=0;
		}
	}
	sort(a+1,a+1+n);
	if(flagA) solve_A();
	else if(flagB) solve_B();
	else if(flag100) solve_100();
	else solve_min();
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
