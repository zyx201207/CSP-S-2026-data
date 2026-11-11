#include <bits/stdc++.h>
using namespace std;
long long n,m,a[605100],h=0,c=0,d=0,ma=-LONG_LONG_MAX;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    d=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			h=a[i];
			if(a[j]==h){
				c++;
			}
			if(a[j]<h){
				d=d-(h-a[j]);
				if(d>=0){
					c++;
				}else{
					d=d+(h-a[j]);
				}
			}
			if(c>ma){
				ma=c;
			}
		}
		d=m;
		c=0;
	}
	cout<<ma;
    return 0;
}
