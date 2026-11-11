#include <bits/stdc++.h>
using namespace std;
struct  y;
int a[10005];
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	int n,m,a,cmp;
	cin >>n>>m>>a>>cmp;
	sort (a+1,a+n+1,cmp);
	int last = m;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a==last){
		ans++;
		last=a;
		
	}		
	}
	
	for(int i=1;i<=n;i++){
		cin >>a;
	}

	cout << ans<<endl;
	
	return 0;
	
} 
