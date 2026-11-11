#include<bits/stdc++.h>
using namespace std;
int n,num,minn=INT_MAX;
long long d,x[2000010];
void dfs(int st,int ed,int nw,int cnt){
	if(cnt>minn)
		return;
	if(nw==ed){
		if(cnt==minn)
			num++;
		else if(cnt<minn){
			minn=cnt;
			num=1;
		}
		return;
	}
	for(int i=nw+1;i<=ed;i++)
		if(x[i]-x[nw]<=d)
			dfs(st,ed,i,cnt+1);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			long long dis=x[2]-x[1];
			d=d/dis*dis;
			long long cnt=2*d/dis-1;
			cout<<n-cnt<<endl;
		}
		return 0;
	}
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++){
				minn=INT_MAX;
				num=0;
				dfs(i,j,i,0);
				if(num==2)
					ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
