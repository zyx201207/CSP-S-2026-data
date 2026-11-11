#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans;
char c[200005];
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	long long x=1,y=l,px=1,py=n,sx=1,sy=1;
	while(x<y){
		if(sx>a[px]){
			px++;
			sx=1;	
		}
		if(sy>a[py]){
			py--;
			sy=1;	
		}
		if(c[px]!=c[py])ans++;
		x++;y--;
		sx++;sy++;
	}
	cout<<ans;
 	return 0;
}
