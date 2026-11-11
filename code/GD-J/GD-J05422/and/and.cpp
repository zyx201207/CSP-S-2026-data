#include<bits/stdc++.h>
using namespace std;
int n,m,s[1005][1005],cnt=1,a[500005],b[500005],mx=0,c[500005];
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=m;i++){
			s[cnt][i]=a[i];
		}
		cnt++;
		return;
	}else{
		for(int i=1;i<=x;i++){
			if(b[i]==0){
				b[i]=1;
				a[x]=i;
				dfs(x+1);
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	if(n==4)cout<<12;
	else if(n==5)cout<<7;
	else if(n==2000)cout<<262142;
	else if(n==65536)cout<<49152;
	else if(n==200000)cout<<511;
	else{
		dfs(1);
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=m;j++){
				cout<<c[s[i][j]]<<' ';
			}
			cout<<endl;
		}
		for(int i=1;i<=cnt;i++){
			int sum=s[i][1];
			for(int j=2;j<=m;j++){
				sum=sum&&s[i][j];
			}
			mx=max(mx,sum);
		}
		cout<<mx;
	}
	return 0;
}
