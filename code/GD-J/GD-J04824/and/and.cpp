#include <bits/stdc++.h>
using namespace std;
long long arr[1000086];
bool two(long long a){
	for ( long long i = 1 ; i > 0 ; i++ ){
		if(pow(2,i) == a)return true;
		if(pow(2,i) > a)return false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for ( long long i = 1 ; i <= n ; i++ ){
		cin>>arr[i];
	}
	sort(arr + 1 , arr + n + 1 , greater<long long>());
	long long tt = arr[1];
	for ( long long i = 2 ; i <= m ; i++ ){
		bool t = two(arr[i]);
		if(t)continue;
		else tt = tt & arr[i];
	}
	cout<<tt;
	return 0;
} 
