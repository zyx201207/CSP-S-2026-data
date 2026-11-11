#include<bits/stdc++.h>
using namespace std;
long long n,step,sum,a[300005];
char c[300005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	step=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	cout<<step;
	return 0;
}
