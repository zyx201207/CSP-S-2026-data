#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,m;
int a[200005],stk[505],top;
bool flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=1;
	}
	if(flag==0){
		map<int,int> res;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]) continue;
			res[a[i]]+=i;
		}
		for(int i=1;i<=m;i++) cout<<res[i]<<" ";
		return 0;
	}
	if(n<=500){
		map<int,int> res;
		for(int i=1;i<=n;i++){
			top=0;
			map<int,int> mp;
			for(int j=i;j<=n;j++){
				if(mp[a[j]]==0){
					stk[++top]=a[j];
					mp[a[j]]=1;
				}else{
					while(stk[top]!=a[j]){
						mp[stk[top]]=0;
						top--;
					}
				}
			}
			for(int j=1;j<=top;j++){
				res[stk[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<res[i]<<" ";
		return 0;
	}
	if(m==2){
		map<int,int> res;
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]) res[a[i]]++;
			else{
				res[a[i]]++;
				res[a[n]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<res[i]<<" ";
		return 0;
	}
	map<int,int> mp,res,vis;
	for(int i=n;i>=1;i--){
		if(vis[a[i]]<i) continue;
		int id=i-1;
		while(mp[a[id]]==0&&id>=1) id--;
		res[a[i]]+=i-id;
		mp[a[i]]++;
		vis[a[i]]=id;
	}
	for(int i=1;i<=m;i++) cout<<res[i]<<" ";
	return 0;
}
