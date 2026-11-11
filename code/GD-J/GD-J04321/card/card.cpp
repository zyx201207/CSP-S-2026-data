#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],t[500005],l[300005],top=0,ans[300005];

void push(int i){
	t[++top]=i;
}

void d(int k){
	top=0;
	for(int i=k;i<=n;i++){
		if(l[a[i]]&&l[a[i]]<=top&&t[l[a[i]]]==a[i]){
			top=l[a[i]];
		}
		else{
			push(a[i]);
			l[a[i]]=top;
		}
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		d(i);
		for(int j=1;j<=top;j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
