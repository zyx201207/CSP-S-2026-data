#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+114514;
ll m,n,num=0,as[N],maxi=-0x3f3f3f3f,sun;
int main(){
	freopen("crystal.in.txt","r",stdin);
	freopen("crystal.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
		for(ll i=1;i<=n;i++)
			cin>>as[i];
		sort(as+1,as+1+n);
		for(ll i=1;i<=n;i++){
			num+=as[i];
			ll dax;
			dax=as[i]*(i-1)-num;
			if(dax<=m){
				if(dax>=maxi){
					maxi=dax;
					sun=i;
				}
			}
		}
	cout<<sun;
	
	return 0;
} 

