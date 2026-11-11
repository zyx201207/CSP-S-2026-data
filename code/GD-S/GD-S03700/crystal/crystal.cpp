#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],i;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++){
		int t=(a[i]-a[i-1])*(i-1);
		if(m<t){
			break;
		}else{
			m-=t;
		}
	}
	if(a[i]==a[i-1]){
		cout<<n;
		return 0;
	}
	int p=m/(a[i]-a[i-1]);
	int s=1,q=i-1;
	while(a[i]==a[i+1]){
		s++;
		i++;
	}
	cout<<max(s+p,q);
	return 0;
}
