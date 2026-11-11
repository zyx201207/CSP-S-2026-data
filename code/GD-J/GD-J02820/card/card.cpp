#include<bits/stdc++.h>
using namespace std;
bool f=1;
int n,m,a[5005],cnt[5005][3005],ans[5005][3005];
queue<int> q;
void p(int x,int num){
	for(int i=x+1;i<=n;i++){
		cnt[i][num]--;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f){
		int cnt=1;
		for(int i=1;i<=m;i++){
			cout<<cnt<<" ";
			cnt++;
		}
	}
	else if(n<=5 && m<=3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cnt[i][j]=cnt[i-1][j];
				if(a[i]==j){
					cnt[i][j]++;
				}
				cout<<cnt[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(cnt[n][a[j]]>1){
					cnt[n][a[j]]--;
					int x=j+1;
					while(a[x]!=a[j]){
						cnt[n][a[x++]]--;
					}
				}
			}
			for(int j=1;j<=m;j++){
				ans[i][j]=ans[i-1][j]+cnt[n][a[i]];
			}
			cnt[n][a[i]]--;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[n][i]<<" ";
		}
	}
	/*for(int i=1;i<=n;i++){
		while(q.size()){
			if(cnt[])
		}
		p(i,q.front());
		q.pop();
	}*/
	return 0;
}
