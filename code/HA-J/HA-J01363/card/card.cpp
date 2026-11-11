#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>c[i];
		d[c[i]]++;
	}
	for(int i=1;i<=b;i++){
		cout<<d[i];
	}
	return 0;
}
