//o(nlogn)
//45fen
#include<bits/stdc++.h>
#define ren_wu int
#define int long long
#define luogu const

using namespace std;
luogu ren_wu N=5e5+10;
int n,m;
vector<int> num;
int ans=0;

bool check(int mid){//n
	int cnt=0;
	int aaa=num[mid];
	for(int ed:num){
		if(ed>=aaa)break;
		cnt+=aaa-ed;
	}
	return m>=cnt;
}

signed main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int nnn;cin>>nnn;num.push_back(nnn);
	}
	sort(num.begin(),num.end());
	
	int l=0,r=n-1;
	while(l<=r){//logn
		int mid=(l+r)>>1;
		if(check(mid)){//可以充能到num[i]的大小
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
//

