#include<bits/stdc++.h>
using namespace std;
int a,b,c[200005],d=-100;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
		cin>>c[i];
	for(int i=1;i<=a;i++){
		if(c[i]>d)d=c[i];
	}
	cout<<d;
	return 0;
}
