#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long n,m,ans,maxx,num;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){	
		num=0;
		ans=0;
		for(int j=i;j<=n;j++){
			if(num>m){
				ans=0;
				num=0;
				break;
			}
			num+=b[j];
			maxx=max(ans,maxx);
			ans++;				
		}	
	}
	cout<<maxx;
	return 0;
} 
