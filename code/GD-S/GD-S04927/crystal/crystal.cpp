#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long n,m,a[N],b[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		a[i]+=a[i-1];
		if(b[i]*i-a[i]<=m){
			ans=i;	
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
} 
