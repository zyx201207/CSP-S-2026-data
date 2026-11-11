#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long n;
	cin>>n;
	long a[n];
	char c[n];
	for(long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	long y=n-1,x=0;
	while(x<y){
		if(c[x]!=c[y]){
			ans+=min(a[x],a[y]);
		}
		if(a[x]>a[y]){
			y--;
			a[x]-=a[y+1];
		}else if(a[y]>a[x]){
			x++;
			a[y]-=a[x];
		}else{
			x++;
			y--;
		}
	}
	cout<<ans;
	return 0;
}
