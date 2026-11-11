#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int c,t,n,d,maxline,cnt=0;
int a[2000010],cur;
vector<int>del;
void dfs(int now,int end,int add){
	if(now==end&&add==maxline){
		cnt++;
		if(cnt>2)return ;
	}
	if(add>=maxline)return;
	if(cnt>2)return;
	for(int i=now;i<=end;i++){
		if(a[i]-a[now]<=d){
			dfs(i,end,add+1);
		}
	}
	return;
}
bool check(int l,int r){
	int num=0,pos=l;
	while(pos<=r&&d>=a[pos+1]-a[pos]){
		int tmp=upper_bound(a+pos+1,a+r+1,a[pos]+d)-a-1;
		if(tmp>pos)num++;
		else break;
		pos=tmp;
	}
	maxline=num;
//	cout<<maxline<<endl;
	dfs(l,r,0);
	if(cnt==2)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<i<<" "<<j<<endl;
				if(check(i,j))cur++;
				cnt=maxline=0;
			}
		}
		printf("%d\n",cur);
		cnt=cur=0;
	}
	return 0;
}
