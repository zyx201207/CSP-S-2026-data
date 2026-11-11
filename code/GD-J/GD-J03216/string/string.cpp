#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct s{
	int x;
	char c;
}a[200001];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){	
		cin>>a[i].x>>a[i].c;
	}	
	int p1=1;
	int p2=n;
	while(p1<p2){
		int y=min(a[p1].x,a[p2].x);
		if(a[p1].c!=a[p2].c)ans+=y;
		if(a[p1].x<a[p2].x){
			
			a[p2].x-=a[p1].x;
			p1++;
		}
		else if(a[p1].x>a[p2].x){
			
			a[p1].x-=a[p2].x;
			p2--;
		}
		else {
			p1++;
			p2--;
		}
	}
	
	cout<<ans;
	return 0;
}
