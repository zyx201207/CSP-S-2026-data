#include<bits/stdc++.h>
using namespace std;
long long a[1010100],b[1010100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m,ans=0,cnt=1;
	cin>>n>>m;
	if(m<=1e9){
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			b[i-1]=a[i]-a[i-1];
			
		}
		while(ans<=m){
			ans+=b[cnt];
			cnt++;
		}
		cout<<cnt-1;
	}
	else{
		cout<<m/(a[2]-a[1])+1;
	}
	return 0;
}