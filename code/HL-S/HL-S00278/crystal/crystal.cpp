#include<bits/stdc++.h>
using namespace std;
const long long N=514114;
long long n,m,a[N],x,y,b,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	x=1;
	y=1;
	ans=1;
	while(n--){
		if(b<=n){
			ans=max(ans,y-x+1);
			if(y!=n){
				y++;
			} 
			else{
				break;
			} 
			b+=(y-x)*(a[y]-a[y-1]);
		}else{
			b-=a[y]-a[x];
			x++;
		}
	}
	cout<<ans+1;
	return 0;
}
