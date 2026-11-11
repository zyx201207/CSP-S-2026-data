#include<bits/stdc++.h>
using namespace std;
long long a[500005];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	} 
	sort(a+1,a+1+n,cmp);
//	for(long long i=1;i<=n;i++){
//		cout << a[i];
//	} 
	long long i=1,j=1;
	long long ans=0;
	long long num=0;
	while(j<=n&&i<=j){
//		cout << i << " " << j << " " << num << endl;
		if(num+a[i]-a[j] > m){
			num-=(a[i]-a[i+1])*(j-i);
			ans=max(ans,j-i+1);
			i++;
		}
		else{
			num+=a[i]-a[j+1];
			j++; 
		}
	}
	cout << ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
*/
