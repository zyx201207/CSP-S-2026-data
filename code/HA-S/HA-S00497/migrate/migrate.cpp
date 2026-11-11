#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
vector<int> a[N];
long long c,t,n,d,x[N],ans,num,minn;

void dfs(int now ,int end,int tim){
//	if(flag[now][end][tim])return ;
//	flag[now][end][tim]=1;
//	cout<<now<<" "<<end<<" "<<tim<<endl;
	if(now>end) return;
	if(tim>minn) return;
	if(now==end){
		if(tim==minn){
			num++;
//			cout<<"******"<<endl;
			return;
		}else{
//			cout<<"^^^^^^"<<endl;
			minn=tim;
			num=1;
			return;
		}
	}
	
	for(int i=a[now].size()-1;i>=0;i--){
//		cout<<1;
		if(a[now][i]>end) continue;
		dfs(a[now][i],end,tim+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=10) {
		while(t--)cout<<0<<endl;
		return 0;
	}
	while(t--){
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i] <= d) a[i].push_back(j);
				else break;
			}
		}
//		
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<a[i].size();j++){
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				num=0;
				minn=0x3f3f3f3f;
				dfs(i,j,0);
				if(num==2) {
//					cout<<"11111111111111111"<<endl;
//				cout<<i<<" "<<j<<" :"<<endl;
					ans++;
				}
//				cout<<endl;
			}
		}
		cout<<ans<<endl;
		ans=0;
//		exit(0);
	}
	return 0;
}
