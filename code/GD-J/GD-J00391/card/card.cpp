#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,a[500005],ans[300005];
int st[500005],cnt;
int sum[500005];
bool flag[500005];
struct node{
	int num,out;
}edge[500005];
bool cmp(node x,node y){
	return x.out<y.out;
}
int top;

void solve1(){
	for(int i=1;i<=n;i++){
		cnt=0;
		memset(sum,0,sizeof(sum));
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(sum[a[j]]==0){
				sum[a[j]]++;
				st[++cnt]=a[j];
			}else{
				while(cnt>0 && st[cnt]!=a[j]){
					sum[st[cnt]]--;
					cnt--;
				}
			}
		}
		
		for(int j=1;j<=cnt;j++){
			flag[st[j]]=true;
		}
		for(int j=1;j<=m;j++){
			if(flag[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	solve1();
	return 0;
	
}










