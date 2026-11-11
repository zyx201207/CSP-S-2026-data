#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+30;
int a[maxn];
int last[maxn],f[maxn];
bool ps[maxn];
int n,d;
int st=0;
int r[maxn],ff[maxn];
void dfs(int num){
	for(int i=num+1;i<=n;i++){
		if(a[i]<=d+a[num]){
	//		cout<<"from"<<a[num]<<"to"<<a[i]<<"found"<<ff[num]+1<<"\n";
			if(ff[num]+1<ff[i]){
				ff[i]=ff[num]+1;
				r[i]=1;
				dfs(i);
			}
			else if(ff[num]+1==ff[i]){
				r[i]+=r[num];
				dfs(i);
			}
		}
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c<=10){
			int ans=0;
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) r[j]=0,ff[j]=1e15;
				ff[i]=0;
				st=i;
				dfs(i);
				for(int j=1;j<=n;j++) {
				//	cout<<ff[j]<<":"<<r[j]<<" ";
					if(r[j]==2) ans++;
				}
				//cout<<"\n";
			}
			cout<<ans<<"\n";
		}
		else{
			int ans=0;
			int arr=1;
			int vis=1;
			int pastt=1;
			int pasvis=1;
			int co=0;
			for(int i=0;i<=n+20;i++) f[i]=0;
			for(int i=1;i<=n;i++){
				last[i]=ps[i];
				for(int j=arr+1;j<=n;j++){
					if(a[i]+d>=a[j]) vis++;
					else break;
				}
				for(int j=pastt;j<=n;j++){
					if(a[i]-d>a[j]) pasvis++,co-=f[j];
					else break;
				}
				if(i>=4&&a[i]-d<=a[i-2]) co+=f[i-2];
				int comp=0;
				co=max(co,comp);
				arr=vis;
				pastt=pasvis;
				if(i>=4){
			//		cout<<"here"<<f[1]<<" "<<f[i-3]<<" "<<"\n";
					ans+=co; 
				}
				if(arr-i==0) continue;
				if(arr-i==1) ps[i]=true;
				if(ps[i-1]) last[i]=1+last[i-1];
				else last[i]=1;
			//	cout<<i<<":"<<last[i]<<"\n";
				if(arr-i==2){
					f[i+1]+=last[i];
				//	cout<<i+1<<f[i+1]<<"\n";
				}
			}
			cout<<ans<<"\n";
		}
		
		//cout<<ans<<"\n";
	}
	
	
}  
/*
hack:
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
5 3
-2 1 2 3 5
*/
