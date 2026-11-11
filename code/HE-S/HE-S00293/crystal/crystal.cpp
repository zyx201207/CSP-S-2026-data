#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[5005],q[5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ch=a[2]-a[1];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt+i*ch>m){
			cout<<i;
			return 0;
		}else{
			cnt+=i*ch;
		}
	}
	cout<<n;
	return 0;
}
