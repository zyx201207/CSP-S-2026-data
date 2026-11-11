//李杜文谦 GZ-S00283 清镇市广大实验学校 
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e6+15;
int c,t;
int n,d;
int a[N],s[N],ans,sumn,ma=INT_MAX,x,y;
bool flag=0;

void dfs(int k,int cnt){
	if(cnt>ma)return ;
	if(k>=y){
		if(cnt==ma){
			ans++;
			if(ans>2){
				ans=0;
				ma=INT_MAX;
				flag=1;
				return ;
			}
		}else if(cnt<ma){
			ma=cnt;
			ans=0;
			flag=0;
			return ;
		}
		return ;
	}
	int su=0;
	for(int j=k+1;su<=d;j++){
		su+=s[j];
		if(d>=su){
			dfs(a[j],cnt+1);
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		cin>>n>>d;
		sumn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=abs(a[i]-a[i-1]);
		}
		for(int i=1;i<n;i++){
			for(int j=n;j>i+d;j){
				x=a[i],y=a[j];
				dfs(x,0);
				if(!flag && ans==2){
					ans=0;
					ma=INT_MAX;
					sumn++;
				}
			}
		}
		cout<<sumn<<"\n";
	}
	return 0;	
}
