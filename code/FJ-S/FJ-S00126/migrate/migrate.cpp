#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll t,n,d,csd,x[N],rs,p[N],minn=1e18,ans;
bool is,fl;
void dfs(int c,int j,int cnt,int tmp){
//	if(fl)return;
	if(c>=j){
//		cout<<"adsa";
		p[cnt+2]=x[j];
		cnt++;
		if(cnt>minn){
//			cout<<minn;
			return;
		}
		for(int i=1;i<=cnt+1;i++){
//			cout<<"yyy";
			if(p[i]+d<p[i+1]){
				return;
			}
		}
		if(cnt<minn){
//			cout<<"\n";
//			for(int i=1;i<=cnt+2;i++){
//				
//				cout<<p[i]<<" ";
//				
//			}
//			cout<<"\n";
			is=0;
			minn=cnt;
		}
		else if(is!=1){
//			cout<<"\n";
//			for(int i=1;i<=cnt+2;i++){
//				
//				cout<<p[i]<<" ";
//				
//			}
//			cout<<"\n";
//			cout<<"dads";
			is=1;
		}
		else{
			fl=1;
			is=0;
		}
		return;
	}
	dfs(c+1,j,cnt,tmp);
	if(fl)return;
	p[2+cnt]=x[c];
	dfs(c+1,j,cnt+1,tmp);
	p[2+cnt]=0;
	return;
}
int main(){
//	freopen("migrate2.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>csd>>t;
//	cout<<"dsadas";
	while(t--){
		ans=0;
		cin>>n>>d;
//		cout<<"dsad";
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(csd==1||csd==2||csd==0){
//			cout<<"dsaasd";
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=n;k++){
						p[k]=0;
					}
//					cout<<"adad";
					p[1]=x[i];
					fl=0;
					rs=0;
					minn=1e18;
					is=0;
					dfs(i+1,j,0,i);
					if(is){
//						cout<<"\n"<<"l,r"<<i<<" "<<j<<"\n";
						ans++;
					}
				}
			}
			cout<<ans<<"\n";	
		}
	}
	return 0;
}
// 10pts 枚举两个端点，dfs出中间经过的岛屿，验证能不能走后统计个数 

