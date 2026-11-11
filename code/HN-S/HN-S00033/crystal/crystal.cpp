#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e12+10;
int a[N];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			cout<<n;
		}
		else{
			while(m>0){
				if(a[i]-a[i-1]==a[i+1]-a[i]){
					cnt=a[i]-a[i-1];
					m-=cnt;
				}
				cout<<cnt;
			}
		}
	} 
	return 0;
} 
