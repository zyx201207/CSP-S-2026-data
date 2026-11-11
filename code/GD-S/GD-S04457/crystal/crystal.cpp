#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[500005];
long long cost=0;
long long ans=0;
long long p=1,q;
bool cmp(long long a, long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>arr[i];
	}
	sort(arr+1,arr+1+n,cmp);
	for(int i=2;i<=n;i++){
		cost+=arr[1]-arr[i];
		//cout <<arr[i];
	}
	ans=n;
	q=n;
	//cout <<"cost:" <<cost <<'\n';
	while(cost>m){
		//cout <<ans <<"-"<<cost <<'\n';
		p++;
		if(arr[p]!=arr[p-1])cost-=(n-p+1)*(arr[p-1]-arr[p]);
		//cout <<"nowcost" <<cost <<'\n';
		ans--;
	}
	cout <<ans;
} 
