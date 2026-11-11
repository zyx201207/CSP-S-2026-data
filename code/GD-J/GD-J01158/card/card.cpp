#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i]; 
	}
	
	
	if(m<=2){
		if(a[n]==1){
			cout << n << " " <<  n-1;			
		}
		else if(a[n]==2){
			cout << n-1 << " " << n;
		}
	}
	
	return 0;
}
