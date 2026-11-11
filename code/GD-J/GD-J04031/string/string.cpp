#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll x=1,y=n,cnt=0;
	while(x<y){
		if(c[x]!=c[y]){
			if(a[x]>a[y]){
				cnt+=a[y];
				a[x]-=a[y];
				y--;
			}else if(a[x]<a[y]){
				cnt+=a[x];
				a[y]-=a[x];
				x++;
			}else{
				cnt+=a[x];
				x++;
				y--;
			}
		}else{
			if(a[x]>a[y]){
				a[x]-=a[y];
				y--;
			}else if(a[x]<a[y]){
				a[y]-=a[x];
				x++;
			}else{
				x++;
				y--;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
//±ù±ù±ù
