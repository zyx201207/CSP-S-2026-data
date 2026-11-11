/* 
QAQ
gei ge guan zhu miao~
id:ABANDON_AC
yong shi 1h
dfs+luan xiang de you hua(jing ran guo le)
etp:80pts
bu shi qi suo zhe jiu,si er bu wang zhe shou.
zai jian OI
I'm a AFOer,a loser.
The End;
return 0;
*/
#include<bits/stdc++.h>
#define AFO return 0; 
using namespace std;
int n,m,a[200010];
int ans=0;
bool c[200010][40];
bool vis[200010];
int cnnt=0;
void dfs(int g,int num){
	if(g==m){
		cnnt++;
		if(num>ans){
			cnnt=0;
			ans=num;
		}
		if(cnnt>1000){
			cout<<ans;
			exit(0);
		}
		return;
	}
	for(int i=n;i>=1;i--){
		if(!vis[i]){
			int next=num&a[i];
			vis[i]=1;
			dfs(g+1,next);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)
		cout<<a[n];
	if(m==2){
		int cnt=0;
		for(int i=n;i>=1;i--)
			for(int j=i-1;j>=1;j--){
				cnt++;
				int sum=a[i]&a[j];
				if(sum>ans){
					cnt=0;
					ans=sum;
				}
				if(cnt>1000)
					break;
			}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=2147483647;
		for(int i=n;i>=1;i--)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			int sum=2147483647;
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				sum&=a[j];
			}
			if(sum>ans){
				ans=sum;
				cnt++;
			}
			if(cnt>1000)
				break;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,a[n]);
	cout<<ans;
	AFO
}
