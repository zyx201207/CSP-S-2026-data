#include<bits/stdc++.h>
using namespace std;
long long n , s = 0 , m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int a[n];
	int x , y;
	for(int i = 0 ; i < n ; i++ ) cin>>a[i];
	sort(a,a+n);
	x = a[n-1];
	y = a[n-2];
	int s1 = x , s2 = y;
	string z1 , z2;
	while(s1 != 0){
		z1 = ((s1%2)+"0")+z1;
	}
	while(s2 != 0){
		z2 = ((s2%2)+"0")+z2;
	}
	string z;
	for(int i = z1.size() - 1 ; i >= 0 ; i-- ) z = (z1[i]-'0' and z2[i]-'0')+"0"+z;
	int sz = 0;
	for(int i = z.size() - 1 ; i >= 0 ; i-- ){
		int bl = 1;
		for(int j = 0 ; j < i ; j++ ) bl = bl*2;
		sz =(z[i]-'0')*bl+sz;
	} 
	cout<<sz;
	return 0;
}
