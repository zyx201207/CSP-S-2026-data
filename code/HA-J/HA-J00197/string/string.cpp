#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

string s;
int x[N];
long long sum,id;
char c[N];

long long c1(long long l,long long r,long long cnt){
	if(l>=id||r<=id){
		return cnt;
	}
	if(x[l]==0){
		c1(l+1,r,cnt);
		
	}
	if(x[r]==0){
		c1(l,r-1,cnt);
		
	}
	if(x[l]>x[r]){
		cnt+=x[r];
		x[l]-=x[r];
		x[r]=0;
		c1(l,r--,cnt);
	}else if(x[l]<x[r]){
		cnt+=x[l];
		x[r]-=x[l];
		x[l]=0;
		c1(l++,r,cnt);
	}else{
		c1(l++,r--,cnt);
	}
}



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x[i] >> c[i];
		sum+=x[i];
	}
	long long kkk=0;
	for(int i = 1;i<=n;i++){
		kkk+=x[i];
		if(kkk>=(sum+1)/2){
			id=i;
			break;
		}
	}
	long long l = 1,r = n,ans=0;
	ans+=c1(l,r,0);
	cout << ans;
	return 0;
}
