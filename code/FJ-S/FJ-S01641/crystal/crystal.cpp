#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt=1,max_cnt=-1;
long long m,x,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		cnt=(a[i]==a[i-1]?cnt+1:1);
		max_cnt=max(cnt,max_cnt);
	}
	
	cout<<max_cnt;
	return 0;
}
