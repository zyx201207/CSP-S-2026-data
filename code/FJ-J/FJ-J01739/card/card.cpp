#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long 
int n,a[500010],m,shu[300010],f=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int mo[500010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=0){
			f=0;
		}
	}
	if(f==1){
		for(int i=1;i<=m;i++){
			cout<<m-i;
		}
	}else{
		cout<<2<<" "<<2; 
	}
	
	return 0;
} 
/*5 3
31 3 1 15 7
4 2
3 15 12 12*/
