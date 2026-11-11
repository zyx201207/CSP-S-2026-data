#include<bits/stdc++.h>
using namespace std;

struct node{
	int lt,rt;
}num[300005];

int n,m,a[500005],jump[500005],ed[300005],ans[300005],o=0;

int recur(int x){
	if(jump[x]==0) return x;
	return jump[x]=recur(jump[x]);
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1 && a[i]<a[i-1]){
			flag=false;
		}
	}
	if(flag){
		for(int i=2;i<=n;i++)
			if(a[i]!=a[i-1])
				cout<<i-1<<" ";
			cout<<n;
		return 0;
	}else if(m==2){
		for(int i=1;i<n;i++)
			if(a[i]!=a[n])
				ans[a[i]]++;
		ans[a[n]]=n;
		cout<<ans[1]<<" "<<ans[2];
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(ed[a[i]]==0){
			ed[a[i]]=i;
		}else{
			jump[i]=ed[a[i]];
		}
	} 
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			j=recur(j);
			ans[a[j]]++;
		}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
