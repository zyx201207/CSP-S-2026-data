#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],mx,q[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int jl=0;
	for(int i=2;i<=n;i++){
		q[i]=a[i]-a[i-1];
		if(mx<q[i]){
			mx=q[i];
			jl=i;
		}
	}
	for(int i=2;i<=n;i++){
		if(m>=q[i]*(i-1)){
			m-=q[i]*(i-1);
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
