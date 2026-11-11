//遵义市滨湖中学 GZ-J00479 胡泽雨 
#include <bits/stdc++.h>
using namespace std;

int n,m,c,d,f;
const long long N=2*1e5;
long long arr[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	c=arr[n-1];
	for(int i=n-1;i>=n-m;i--){
		c&=arr[i];
	}cout<<c;
	fclose(stdin);
	fclose(stdout);
}

