#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
	long long a;
	char c;
}a[200090];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,y=0;
	long long x=0;
	cin>>n;
	y=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	long long x1=0;
	for(int i=1;i<=n;i++){
		if(a[i].c!=a[y].c){
			x+=min(a[i].a,a[y].a);
			if(a[i].a<a[y].a){
				a[y].a-=a[i].a;
				continue;
			}
			else if(a[i].a>a[y].a){
				a[i].a-=a[y].a;
				i--;
				y--;
			}
		}
	}
	cout<<x;
	return 0;
} 
