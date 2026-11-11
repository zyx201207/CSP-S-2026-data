#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,cnt,maxx,ans;
int a[N],b[5];
bool flag,o;
void dfs(int step,int s,int sum){
	if(step>n){
		if(s==m){
			cnt=max(sum,cnt);
		}
		return;
	}
	if(s>m)  return;
	dfs(step+1,s,sum);
	if(s==0){
		dfs(step+1,1,a[step]);
	} 
	else{
		dfs(step+1,s+1,a[step]&sum);
	} 
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(__gcd(a[i]+1,2ll)!=2){
			flag=true;
		}
		if(a[i]>4){
			o=true;
		}else{
			b[a[i]]++;
		}
	}
	if(n<=20){
		dfs(1,0,1);
		cout<<cnt;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout<<cnt;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(!flag){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(!o){
		if(m<=b[4]){
			cout<<"4";
		}
		if(m<=b[3]){
			cout<<"3";
		}
		if(m<=b[2]+b[3]){
			cout<<"2";
		}
		if(m<=b[1]+b[3]){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}
	return 0;
}
