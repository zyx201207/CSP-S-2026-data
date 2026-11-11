#include<bits/stdc++.h>
using namespace std;
//using ll=long long;
const int N=500005;
int m,n;
int a[N];
int main(){
	freopen("crystal.in.txt","r",stdin);
	freopen("crystal.out.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int k=a[2]-a[1],x=k,ans=0;
	while(m>0){
		m-=x;
		if(m<0) break;
		x+=k;
		ans++;
	}
	cout<<ans;
	return 0;
}             
