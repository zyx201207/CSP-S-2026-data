#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,x,y;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}x=1,y=n;
	while(x<=y){
		if(c[x]!=c[y]){
			sum+=min(a[x],a[y]);
			
		}if(a[x]<a[y]){
			a[y]-=a[x];
			x++;
			
		}else if(a[x]>a[y]){
			a[x]-=a[y];
			y--;
		}else if(a[x]==a[y]){
			x++;
			y--;
		}
		
	}
	cout<<sum;
	return 0;
}

