#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
long long n,m,x,p;
int ans;
int ar[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		ans=max(ans,ar[i]);
	}
	if(m==1){
		cout<<ans;
	}else if(m==n){
		x=ar[1];
		for(int i=2;i<=n;i++){
			x&=ar[i];
		}
		cout<<x;
	}else if(m==2){
		for(int i=1;i<n;i++){
			x=ar[i];
			for(int j=i+1;j<=n;j++){
				x&=ar[j];
				p=max(p,x);
				x=ar[i];
			}
		}
		cout<<p;
	}else{
		sort(ar+1,ar+n+1,greater<int>());
		cout<<ar[m];
	}
	return 0;
}
