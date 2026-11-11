#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	vector<int> a(5),b;
	a[0]=1;
	a[1]=3;
	a[2]=2;
	a[3]=4;
	a[4]=5;
	copy(a.begin(),a.end(),b.begin()+2);
	cout<<b[3];
	return 0;
}
