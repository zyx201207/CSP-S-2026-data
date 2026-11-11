#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500005;
int num[MAXN],n,m,maxtime=1;
map<int,int>tong;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		tong[num[i]]++;
		maxtime=max(maxtime,tong[num[i]]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j)continue;
			if(abs(num[i])+abs(num[j])==m)maxtime+=2,cout<<num[i]<<" "<<num[j]<<endl;
		}
	}
	return 0;
} 
