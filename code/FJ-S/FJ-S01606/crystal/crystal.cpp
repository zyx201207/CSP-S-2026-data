#include<bits/stdc++.h>
using namespace std;
long long s[500005];
long long q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	q[1]=0;
	cin>>s[1];
	for(int i=2;i<=n;i++){
		cin>>s[i];
		sort(s+1,s+i+1);
		q[i]=q[i-1]+(s[i]-s[i-1])*(i-1);
	}
	for(int i=n;i>=1;i--){
		if(q[i]<=m){
			cout<<i;break;
		}
	}
	
	return 0;
}
