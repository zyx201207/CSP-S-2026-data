#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
    for(int i=1;i<=n;i++){
		if(m>=(a[i+1]-a[i])*i){
			m-=abs(a[i+1]-a[i])*i;
			ans++; 
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
} 

