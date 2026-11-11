#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool flag[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[i]=1;
	}
	int base=(((int)1)<<29),ans=0;
	for(int i=29;i>=0;i--){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(flag[i]&&(a[i]&base)){
				sum++;
			}
		}
		if(sum>=m){
			ans+=base;
			for(int i=1;i<=n;i++){
				if(flag[i]&&(!(a[i]&base))){
					flag[i]=0;
				}
			}
		}
		base>>=1;
	}
	cout<<ans;
} 
