#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500500];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    sort(a+1,a+1+n);
    if (n<10)cout<<m<<" "<<a[1]<<" "<<n; 
	else if (n>=10)cout<<n<<" "<<a[n]<<" "<<a[n];                                  
	return 0;
}

