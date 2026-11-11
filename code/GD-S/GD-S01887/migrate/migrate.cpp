#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10; 
int ans;
int cnt;
int farr[N];
int n,d,f[N],T;
int check(int x,int y,int len){
	int ti=x+1; 
	while(f[ti]-f[x]<=d){
		if(ti==y){
			return len;
		}
		ti++;
	}
	ti--;
	if(ti==x){
		return 0;
	}
	return check(ti,y,len+1);
}
void dfs(int x,int y,int zong){
	if(zong==0){
		if(f[y]-f[x]<=d){
			ans++;
		}
		return ;
	} 
	for(int i=x+1;i<y;i++){
		if(f[i]-f[x]<=d){
			dfs(i,y,zong-1);
		}
		else return ;
	}
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c=0;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int last=0;
		for(int i=1;i<=n;i++){
			cin>>f[i];
		}
		cnt=0;
		if(c==11||c==12){
			int cha=f[2]-f[1];
			int aa=1.0*d/cha;
			int sum=0;
			for(int i=4;i<=2*aa;i+=2){
				sum+=max(0ll,(n-i+1));
			} 
			cout<<sum<<endl;
			continue;
		}
		if(c==13||c==14){
			cout<<0<<endl;
			continue;
		}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=0;
					int k=check(i,j,1);
				//	cout<<i<<" "<<j<<" "<<k<<endl;
					if(k){
						dfs(i,j,k-1);
						if(ans==2) cnt++;
					}
				}
			}
			cout<<cnt<<endl;
		
	}
	return 0;
}

