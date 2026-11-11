#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,i,x;
	long long c[a+5];
	cin>>a>>b;
	for(i=0;i<a;i++)
		cin>>c[i];
	if (b==1){
		x=c[0];
		for(i=0;i<a;i++){
			if (c[i]>x)
				x=c[i];
		}
	}
	if (b==a){
		x=c[0];
		for(i=1;i<a;i++){
			x&=c[i];
		}
	}
	
	return 0;
}
