#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long a[maxn],b[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,t,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=1;
		while((1<<x)<a[i]){
			x++;
		}
		b[a[i]]=(a[i]^x);
	}	
	t=m;
	sort(a+1,a+1+n);
	for(int i=n;i>=n-t+1;i--){
		if(i==0){
			ans=0;
			break;
		}
		if(i==n)ans=a[n];
		else{
			if(b[ans]==a[i])t++;
			else ans&=a[i];
		}
	}
	cout<<ans;
} 
