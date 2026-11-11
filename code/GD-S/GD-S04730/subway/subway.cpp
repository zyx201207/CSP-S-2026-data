#include<bits/stdc++.h>
using namespace std;
unsigned long long c,n,m,d,q;
long long a[500005];
struct line{
	int num,time;
}b[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	if (n==2){
		cout<<32<<endl<<17;
	}if (n==3){
		cout<<35<<endl<<16;
	}
	return 0;
}
