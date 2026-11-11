#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int x=2,y=2;
	for(int i=1;i<=n;i++){
		if(x==0){
			y++;
			x=y;
			b[i]=y;
			x--;
		}
		else{
			b[i]=y;
			x--;	
		}
		
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	long long  cha=a[2]-a[1];
	long long p=m/cha;
	if(p>n) cout<<n;
	else cout<<b[p];
	return 0;
}

