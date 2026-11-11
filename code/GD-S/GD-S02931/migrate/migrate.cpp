#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d;
ll a[10005];
bool go(ll s,ll e,ll sp){
	ll r=e-s;
	if(r>sp&&r%sp!=0){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	//优化数组 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//打开文件 
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	//输入 
	cin>>c>>t;
	while(t--){
		ll cnt=0,dis=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2){
				if((a[i]-1)!=a[i-1]){
					dis+=1;
				}
			}
		}n=n-dis;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(go(a[i],a[j],d)){
					cnt+=1;
				}
			}
		}cout<<cnt<<"\n";	
	} 
	//输出文件 
	//fclose(stdin);
	//fclose(stdout);	
	return 0;
} 
