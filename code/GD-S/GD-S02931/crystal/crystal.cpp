#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//打开文件 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//输入 
	cin>>n>>m;
	ll ms=INT_MAX,mb=-(INT_MAX);	
	ll ks=0,kb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//变化
	while(m){
		ms=INT_MAX;
		for(int i=1;i<=n;i++){
			if(a[i]<ms){
				ms=a[i];
				ks=i;
			}if(a[i]>mb){
				mb=a[i];
				kb=i;
			}
		}for(int i=1;i<=n;i++){
			if(ms==a[i]){
				a[i]+=1;
				m=m-1;
			}
		}
	}
	//计数 
	ll mbp=0,ans=0;
	for(int i=ks;i<=kb;i++){
		ll cnt=1;
		for(int j=ks;j<=kb;j++){
			if(a[i]==a[j]&&i!=j){
				cnt+=1;
			}
		}
		if(mbp<cnt){
			mbp=cnt;
			ans=i;
		}
	}cout<<mbp; 
	//输出文件 
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
