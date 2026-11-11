#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+3;
int n;
int num[N];
int c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string ans;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	int cnt=0;
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=num[i];j++){
			for(int p=n/2;p>=1;p--){
				for(int q=num[p];q>=1;q--){
					if(c[j]!=c[q]){
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
} 
