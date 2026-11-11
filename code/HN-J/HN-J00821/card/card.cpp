#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t;//tÎªÂÖÊý 
int a[300100],m;
int s[300010];
int d[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		d[a[i]]++;
	
	}
	for(int i=1;i<=n;i++){
		if(d[a[i]]>1){
			d[a[i]]--;
		}else{
			cout << i << ' ';
		}
	}	 
	return 0;
}
/*
10 3
2 3 1 2 1 3 2 3 1 2 1
*/
