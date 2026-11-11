/*
#include<bits/stdc++.h>
using namespace std; 
const int N=2e5+10;
int mark[N]; 
struct stu{
	int x;
	int last;
}a[N];
void twojin(int X){
	int x1=a[X].x;
	int cnt=0;
	int flag=0;
	while(x1!=0){
		cnt++;
		x1/=2;
		if(x1%2==1&&flag==0){
			flag=cnt;
			break; 
		}
	}
	a[X].last=flag;
}
bool cmp(stu x,stu y){
	if(x.last==y.last){
		return x.x>y.x;
	}
	return x.x>y.x;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		twojin(i);
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1].x;
	cout<<ans<<"<"<<"\n";
	for(int i=2;i<=m;i++){
		ans=ans&a[i].x;
		cout<<a[i].x<<"---------"<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
//废案 以下为部分分代码 
*/
#include<bits/stdc++.h>
using namespace std; 
const int N=2e5+10; 
int a[N];
int n,m;
int maxn=-1e9;
void dfs(int x,int ans,int cnt){
	if(cnt==m||x==n+1){
		if(cnt==m){
			maxn=max(ans,maxn);
		}
		return ;
	}
	if(ans==0){
		dfs(x+1,a[x],cnt+1);
		dfs(x+1,ans,cnt);
	}
	else{
		dfs(x+1,ans&a[x],cnt+1);
		dfs(x+1,ans,cnt);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1,0,0);
		cout<<maxn;
	}
	if(n>=10){
		int cnt=0;
		sort(a+1,a+1+n);
		cnt=a[n];
		for(int i=n-1;i>=1;i--){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	return 0;
}
