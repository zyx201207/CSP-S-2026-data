#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],cf[N];
long long sum=0;
int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cf[i]=a[i]-a[i-1];
	}
	while(m--){
		int minn=5e5;
		for(int i=1;i<=n;i++){
			if(cf[i]==0){
				continue;
			}
			minn=min(cf[i],minn);
			cout<<minn<<' ';
		}
		cf[minn]++;
	}
	for(int i=1;i<=n;i++){
		if(cf[i]==0){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
