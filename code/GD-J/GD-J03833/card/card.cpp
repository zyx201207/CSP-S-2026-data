#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5050];
int pai[5050];
int countt[5050];
int ans[5050];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])flag=0;
	}int cnt=0;
	if(flag){
		int tmp=1;
		int now=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]==now)tmp++;
			else{
				ans[now]=i-1;
				cout<<ans[now]<<" "; 
				now=a[i],tmp=1;
			}
		}cout<<n;
		return 0;
	}if(m==2){
		int tmp=1;
		int now=a[n];
		for(int i=n-1;i>=1;i--){
			if(now!=a[i]){
				ans[now]=n;
				ans[a[i]]=n-tmp;
				break;
			}else tmp++;
		}for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			if(countt[a[j]]){
				for(int k=cnt;k>0;k--){
					countt[pai[k]]=0;
					if(pai[k]==a[j]){
						cnt=k;
						break;
					}
				}pai[cnt]=a[j];
				countt[a[j]]=1;
			}else{
				cnt++;
				pai[cnt]=a[j];
				countt[a[j]]=1;
			}
		}for(int i=1;i<=m;i++){
			ans[i]+=countt[i];
			countt[i]=0;
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
