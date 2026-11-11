#include <bits/stdc++.h>
using namespace std;
long long a[200005];long long s[200001];
char c[200001];
//cbbbc
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		
		cin>>a[i]>>c[i];
	}
	int x=1,y=n;
	while(x<=y){
		long long m=min(a[x],a[y]);
		if(c[x]!=c[y]){
			ans+=m;
		}
		a[x]-=m;
		if(!a[x]){
			x++;
		}
		a[y]-=m;
		if(!a[y]){
			y--;
		}
		
		
	}
	cout<<ans;
	return 0;
}

