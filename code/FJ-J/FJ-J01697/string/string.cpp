#include<bits/stdc++.h>
#define int long long
using namespace std;
struct P{
	char c;
	int x;
}a[200005];
int n,ans,m,mi;
signed main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		m+=a[i].x;
	}
	int l=1,r=n,x=0,y=0;
	while(1){
		if(x+a[l].x>m/2){
			while(y<m/2){
				if(y+a[r].x>m/2){
					if(a[r].c!=a[l].c)ans+=m/2-y;
					a[r].x-=m/2-y;
					y=m/2;
					break;
				}
				if(a[r].c!=a[l].c)ans+=a[r].x;
				y+=a[r].x;
				r--;
			}
			break;
		} 
		x+=a[l].x;
		while(y<x){
			if(y+a[r].x>x){
				if(a[r].c!=a[l].c)ans+=x-y;
				a[r].x-=x-y;
				y=x;
				break;
			}
			if(a[r].c!=a[l].c)ans+=a[r].x;
			y+=a[r].x;
			r--;
		}
		l++;
	}
	cout<<ans;
	return 0;
}
