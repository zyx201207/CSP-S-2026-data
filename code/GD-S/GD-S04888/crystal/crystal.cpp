#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],b[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			b[i]=a[i]-a[i-1];
		}
	}bool f=true,ff=true;
	for(int i=3;i<=n;i++){
		if(b[i]!=b[i-1]){
			f=false;
		}if(a[i]!=i){
			ff=false;
		}
	}if(f==true||ff==true){
		int x=m/b[n],y=1,yy=2,c=1;
		for(int i=1;;i++){
			if(y>x){
				cout<<c;
				return 0;
			}else{
				y+=yy;
				yy++;
				c++;
			}
		}
		return 0;
	}
	return 0;
}
