#include<bits/stdc++.h>

const int N=5*1e5+5;
using namespace std;
int n,m,a[N],ans[N],ans2[N],v;
struct node{
	bool flag,flag2;
	int x;
}s[N];
bool y[N];
int num,cnt[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(!s[a[j]].flag&&!y[a[j]]){
				num++;
				s[a[j]].flag=1;
				s[a[j]].x=num;
				cnt[num]=a[j];
			}else if(s[a[j]].flag&&!s[a[j]].flag2&&!y[a[j]]){
				s[a[j]].flag2=1;
				int u=s[a[j]].x;
				for(int k=u;k<=num;++k){
					y[cnt[k]]=1;
				}
				cnt[u]=a[j];
				num=u;
			}
			/*if(i==7){
				cout<<num<<"num "<<j<<"j "<<"\n";
				for(int k=1;k<=num;++k)cout<<cnt[k]<<" ";
				cout<<"\n";
			}*/
		}
		//cout<<i<<"i ";
		for(int j=1;j<=num;++j){
			ans[cnt[j]]++;
			//cout<<cnt[j]<<" ";
			//cout<<i<<" "<<cnt[j]<<" "<<ans[cnt[j]]<<"\n";
			cnt[j]=0;
		}
		//cout<<"\n";
		//for(int j=1;j<=m;++j)cout<<y[j]<<" ";
		//cout<<"\n";
		for(int j=1;j<=m;++j){
			s[j].x=0;
			s[j].flag=0;
			s[j].flag2=0;
			y[j]=0;
		}
		num=0;
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	/*
	4 3
	1 2 1 3
	
	10 3
	3 1 2 1 3 2 3 1 2 1
	*/
	return 0;
}
