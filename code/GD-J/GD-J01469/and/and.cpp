#include<bits/stdc++.h>
using namespace std;
long long n , m ,sum;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin >> n >> m ;
    for(long long i = 1 ; i <= n ; i ++){
    	cin >> a[i];
	}
	sort(a+1, a+n+1 , greater<long long>());
	if(m>=1){
		sum=a[1];
	}
	for(long long i = 1 ; i <= m ; i ++){
	    sum=(long long)(sum&a[i]);
	}
	cout << sum << endl;
	return 0;
}
