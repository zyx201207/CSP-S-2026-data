#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,c[200005],f,g=0;
	cin>>a>>b;
	for(long long i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	f=c[a-1];
	for(long long i=a-2;i>a-b-1;i--){
		f=f&c[i];
	}
	cout<<f;
	return 0;
	}
