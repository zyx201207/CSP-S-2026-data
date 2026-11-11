#include<bits/stdc++.h>
using namespace std;
long long n,m,num[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++){
		int ls=0;
		for(int j=1;j<=i;j++){
			ls+=num[i]-num[j];
			if (ls>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	cout<<n;
	return 0;
} 
