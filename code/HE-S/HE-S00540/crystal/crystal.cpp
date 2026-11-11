#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=5*1e5+9;
long long cst[MAXN],m,n,cur;
map<long long,long long> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool Less=true;
	for(int i=0;i<n;i++){
	cin>>cst[i];
	if(i==0)
	continue;
	if(i!=1&&cst[i]-cst[i-1]!=cur)
	Less=false;
	cur=cst[i]-cst[i-1];
	mp[i*(i+1)/2]=i;
	}
	if(Less){
		int plusm=m/cur;
		while(plusm--){
			if(mp[plusm+1]!=0){
				cout<<mp[plusm+1];
				break;
			}
	}
		return 0;
	}
	long long maxn=-1;
	for(int i=0;i<n;i++){
		long long can=0,M=m;
		for(int j=i;j>=0;j--){
			if(cst[i]-cst[j]<=M){
				M-=(cst[i]-cst[j]);
				can++;
			}
			else break;
		}
		if(maxn<can)
		maxn=can;
	}
	cout<<maxn;
	return 0;
}
