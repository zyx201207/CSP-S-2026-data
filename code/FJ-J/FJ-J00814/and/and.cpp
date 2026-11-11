#include<bits/stdc++.h>
using namespace std;
long long a[2000005],b[2000005],res=1,ans=0,n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		b[i]=a[n-i+1];
	}
	while(b[m]!=0){
		bool flag=false;
		for(int i=2;i<=m;i++){
			if(b[i]%2!=b[1]%2){
				flag=true; 
			}
			b[i]/=2;
		}
		if(flag==false){
			ans+=res;
		}
		b[1]/=2;
		res*=2;
	}
	cout<<ans;
	return 0;
} 
