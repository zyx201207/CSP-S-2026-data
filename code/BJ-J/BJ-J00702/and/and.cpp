#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,num[100005];
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>num[i];
	}
	cout<<num[a];
	return 0;
}
