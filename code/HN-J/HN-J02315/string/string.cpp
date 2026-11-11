#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,sum=0;
	cin>>a;
	for(int i=0;i<=a;i++){
		b=a+1-i;
		cout<<b<<" ";
	}
	for(int q=1;q*2<=b;q++){
		sum=b+1-q;
		cout<<sum<<" ";
	}
	return 0;	
}
