#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],c=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(m--){
		int minn=2e9,mi;
		for(int i=1;i<=n;i++){
			minn=min(a[i],minn);
	        if(minn=a[i])mi=i;
		}
		a[mi]++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])continue;
		c++;
	}
	cout<<c;
	return 0;
}
