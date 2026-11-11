#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b,num[100005];
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>num[i];
	}
	for(long long i=1;i<=b;i++){
		cout<<i<<" ";
	}
	return 0;
}