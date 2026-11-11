#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],t[500005],ans=-1;

int count(){
	int maxs=-1,cnt;
	for(int i=1;i<n;i++){
		cnt=1;
		for(int j=i+1;j<=n;j++){
			if(t[i]==t[j]) cnt++;
		}
		maxs=max(cnt,maxs);
	}
	//cout<<maxs<<endl;
	return maxs;
}
void dfs(int temp){
	if(temp>=m){
		ans=max(ans,count());
		return ;
	}
	for(int i=1;i<=n;i++){
		t[i]++;
		//cout<<i<<' ';
		dfs(temp+1);
		t[i]--;
	}
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool bola=true,bolb=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
		if(a[i]!=i) bola=false;
		else if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2]) bolb=false;
	}
	if(bola){
		int v=0;
		while(m){
			v++;
			m-=v;
		}
		if(m<0) cout<<v;
		else cout<<v+1;
	}
	else if(bolb){
		int v=0,h=a[2]-a[1];
		while(m){
			v++;
			m-=v*h;
		}
		if(m<0) cout<<v;
		else cout<<v+1;
	}
	else{
		dfs(0);
		cout<<ans;
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
