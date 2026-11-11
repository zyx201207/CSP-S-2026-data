#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+3,K=30;
int n,m,ans,a[N],s[N][K];
bitset<N>canuse;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<30;j++){
			if((a[i]>>j)&1){
				s[i][29-j]=1;
			}
			else s[i][29-j]=0;
		}
	}
	for(int i=1;i<=n;i++)
		canuse[i]=1;
	for(int j=0;j<30;j++){
		int nowsum=0;
		for(int i=1;i<=n;i++){
			if(canuse[i]&&s[i][j])nowsum++;
		}
		if(nowsum<m)
			continue;
		else{
			ans+=(1<<(29-j));
			for(int i=1;i<=n;i++)
				if(s[i][j]==0)canuse[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
//10:15-11:13
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
