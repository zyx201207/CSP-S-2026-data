#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int a[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int cnt=0;
	if(m==1){
		for(int i=0;i<=n;i++){
			int x;
			cin>>x;
			cnt=max(cnt,x);
		}
	}else if(m==n){
		cnt=0xffffffff;
		for(int i=0;i<=n;i++){
			int x;
			cin>>x;
			cnt=cnt^x;
		}
	}
	cout<<cnt;
	return 0;
}

