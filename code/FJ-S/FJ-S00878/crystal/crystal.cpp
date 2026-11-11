#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],cnt,sum,c;
bool f=1;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		int b=a[2]-a[1];
		if(a[i]-a[i-1]!=b) f=0;
	}
	if(f==1){
		int b=m/(a[2]-a[1]);
		if(b>n){
			for(int i=1;i<=b;i++){
			c+=i;
			if(c>=b){
				cout<<i+1;
				return 0;
			}
			}
		}
		else cout<<b;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		a[1]+=1;
		for(int j=1;j<=n;j++){
			if(a[j]!=a[j-1]){
				continue;
			}
			cnt++;
		}
		sum=max(sum,cnt);
		sort(a+1,a+1+n);
	}
	cout<<sum;
	return 0;
} 
