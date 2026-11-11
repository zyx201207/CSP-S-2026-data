#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,far;
}a[5010][5010];
long long x[2000010];
vector<int> v[2000010];
long long bb,c,t,n,d;
long long ans;
void dfs(int x,int xx){
	for(int i=0;i<v[x].size();i++){
		if(a[bb][v[x][i]].far>xx||a[bb][v[x][i]].num==0) a[bb][v[x][i]].num=1,a[bb][v[x][i]].far=xx;
		else if(a[bb][v[x][i]].far==xx)a[bb][v[x][i]].num++;	
		dfs(v[x][i],xx+1);
	}
	if(x==n)return;	
}
bool isA(){
	for(int i=2;i<n;i++){
		if((x[i]-x[i-1])!=(x[i+1]-x[i]))return false;
	}
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=300){
			memset(v,0,sizeof(v));
			memset(a,0,sizeof(a));
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d) v[i].push_back(j);
					else break;
				}
			}
			for(bb=1;bb<=n;bb++) dfs(bb,1);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[i][j].num==2)ans++;
				}
			}
			cout<<ans<<endl;
		}
		else if(isA()){
			long long cha=x[2]-x[1];
			if(cha>d){
				cout<<0<<endl;
				continue;
			}
			int i=1;
			while(d>=cha){
				cha*=3;
				i++;
			}
			n/=3*i;
			for(int i=4;i<=n;i++){
				ans+=n-i+1;
			}
			cout<<ans;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
} 
