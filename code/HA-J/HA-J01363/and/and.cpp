#include<bits/stdc++.h>
using namespace std;
long long a,b,c[200005],d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	d=c[a];
	for(long long i=a-1;i>a-b;i--){
		d=d&c[i];
	}
	cout<<d;
	return 0;
}
