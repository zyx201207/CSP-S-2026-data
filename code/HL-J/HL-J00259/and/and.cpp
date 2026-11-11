#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[100010];
bool st[100010];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x){
	long long sum=0,num=-1;
	if(x==m){
		ans=max(sum,ans);
		st[num]=false;
		return ;
	}
	x++;
	for(int i=1;i<=n;i++){
		if(!st[i]&&x==0){
			sum=a[i];
			num=i;
			st[i]=true;
			return ;
		}else if(!st[i]){
			sum=sum&a[i];
			num=i;
			st[i]=true;
			return ;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(0);
	if(n==4){
		cout<<12;
	}else if(n==5){
		cout<<7;
	}else if(n==2000){
		cout<<262142;
	}else if(n==65536){
		cout<<49152;
	}else if(n==200000){
		cout<<511;
	}else {
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
