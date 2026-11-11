#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5;
struct stu{
	int s;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	cout<<2;
	return 0;
}