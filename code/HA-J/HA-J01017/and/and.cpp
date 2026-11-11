#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	long long c[a+10]={0};
	for(int i=1;i<=a;i++){
		cin>>c[i];
		if(i==a){
			cout<<c[i];
		}
	}
return 0;
}
