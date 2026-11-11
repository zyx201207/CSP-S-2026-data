#include<bits/stdc++.h>
#define int long long
const int N=5e5+5;
using namespace std;
struct mm{
	int num=0;
	int number=0;
}b[N];
int ans,n,m,a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=-1*n;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<=i) b[i].num+=i-a[j],b[i].number++;
			else break;
		}
		if(b[i].num>m){
			ans=b[i-1].number;
		} 
	}
	cout<<ans;
	return 0;
}
