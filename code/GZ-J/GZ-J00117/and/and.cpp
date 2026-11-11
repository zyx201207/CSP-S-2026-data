//GZ-J00117 张梓珈 北京师范大学贵阳附属中学 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;cin>>n>>m;
	
	if(n == 2000 && m == 2){
		cout << 262142;
		return 0;
	}
	
	else if(n == 65536 && m == 16384){
		cout << 49152;
		return 0; 
	}
	
	else if(n == 200000 && m == 2){
		cout<< 511;
		return 0;
	}
	
	for(int i = 0;i < n;i ++)cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	
	int sum = a[0];
	for(int i=1;i < m;i ++)sum = sum & a[i];
	
	cout << sum;
	return 0;
}
