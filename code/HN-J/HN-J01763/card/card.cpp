#include<bits/stdc++.h>

using namespace std;

int n,m;
long long a[500010],lst[500010],ans[500010],now[500010];
bool f=1;
void work(){
	for(int i=1;i<=n;i++){
		lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<lst[i]<<" ";
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
	}
	if(f){
		work();
		return 0;
	}
	for(int i=1;i<=n;i++){
		int top=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=top;k++){
				if(now[k]==a[j]){
					top=k-1;
					break;
				}
			}
			now[++top]=a[j];
		}
		bool fl[500010]={0};
		for(int j=1;j<=top;j++){
			if(fl[now[j]]==0){
				fl[now[j]]=1;
				ans[now[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}
