#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,x,mini=35,ans=0,ct=0;
int cnt[37],b[N][37],f[35],er[35]={1};
queue<int>q;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ct=0;
		cin>>x;
		while(x){
			b[i][ct++]=x%2;
			x/=2;
		}
		for(int j=0;j<=ct;j++){
			if(b[i][j])cnt[j]++; 
		}
	}
//	return 0;
	for(int i=35;i>=0;i--){
		if(cnt[i]<m){
			mini=i;
			continue;
		}
	}

	mini-=1;
	for(int i=1;i<=n;i++){
		if(b[i][mini]){
			q.push(i);
		}else{
			for(int j=0;j<=35;j++)
			if(b[i][j])cnt[j]--;
		}
	}
//	return 0;
	for(int i=mini;i>=0;i--){
		int slt=q.size();
		if(cnt[i]<m){
			f[i]=0;
			continue;
		}else f[i]=1;
		for(int j=1;j<=slt;j++){
			int id=q.front();
			q.pop();
			if(!b[id][i]){
				for(int k=0;k<=i;k++){
					if(b[id][k])cnt[k]--;
				}
			}
			else q.push(id);
		}
	}
//	return 0;
	for(int i=0;i<=mini;i++){
		if(f[i]){
			ans+=er[i];
		}
		er[i+1]=er[i]*2;
	}
	cout<<ans;
	return 0;
}/*
5 3
31 3 1 15 7

111
 11
  1
111
111
*/
