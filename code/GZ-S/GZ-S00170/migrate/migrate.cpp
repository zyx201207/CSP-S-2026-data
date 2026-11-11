//GZ-S00170 张哲睿 贵阳市新世界学校
#include<bits/stdc++.h>
using namespace std;
int x[100011],s[100001],ans[10001],ansbs[10001];int n,d;
int dfs(int x,int bs){
	if(bs==ansbs[x]){
		ans[x]++;
		return 0;
	}else if(bs<ansbs[x] || ansbs[x]==0){
		ansbs[x]=bs;
		ans[x]=1;
	}else{
		return 0;
	}
	int sss=0;
	for(int i=x+1;i<=n;i++){
		sss+=s[i];
		if(sss>d){
			break;
		}
		dfs(i,bs+1);
	}
	return 0;
}
int main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			ans[i]=0;
			ansbs[i]=0;
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			s[i]=x[i]-x[i-1];
		}
		if(c==11 || c==12){
			int cha=x[2]-x[1],ans=((d/cha)-1)*n-((d/cha)+1)*(d/cha)/2+1;
			if(d>=cha){
				cout<<ans;
			}else{
				cout<<0;
			}
			cout<<'\n';
			continue;
		}
		int sum=0,k=0;
		dfs(1,0);
		long long aans=0;
		for(int i=1;i<=n;i++){
			aans+=ans[i];
		}
		cout<<aans<<'\n'; 
	}
	return 0;
} 
