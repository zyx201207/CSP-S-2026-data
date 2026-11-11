#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
int a[1000000];
int d[1000000];
queue<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0) d[i]=a[i]-a[i-1];
	}
	sort(a,a+n);
	int sum=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		q.push(a[i]);
		sum+=a[i];
		while(a[i]*q.size()-sum>m){
			sum-=q.front();
			q.pop();
		}
		cnt=max(cnt,(int)q.size());
	}
	cout<<cnt;
	return 0;
}