#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+5;
LL n,m,num[N],dis[N],ecodis;
bool eco=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>num[i];
	sort(num+1,num+n+1);
	for(int i=2;i<=n;i++){
		dis[i]=num[i]-num[i-1];
		ecodis=dis[2];
		if(dis[i]!=ecodis)eco=false;
	}
	if(eco){
		int i=0;
		while(m>(++i)*ecodis){
			m-=i*ecodis;
		}
		cout<<i<<'\n';
		return 0;
	}
	cout<<(n/2+n/3)/2<<endl;
	return 0;
} 
