#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010]={};
vector <int > lasta[300010];
int pan[500010]={};
int ans[300010]={},lastatot[300010]={},lastaz[300010]={};

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lasta[a[i]].push_back(i);
		lastaz[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(lastaz[i]<1) break;
		for(int j=lasta[i][0];j<lasta[i][lastaz[i]-1];j++){
			pan[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(pan[i]==0) ans[a[i]]++; 
	}
	for(int k=2;k<=n;k++){
		
		for(int j=lasta[a[k-1]][lastatot[a[k-1]]]+1;j<lasta[a[k-1]][lastatot[a[k-1]]+1];j++){
			pan[j]--;
		}
		for(int i=k;i<=n;i++){
			if(pan[i]==0) ans[a[i]]++; 
		}
		lastatot[a[k-1]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
