#include<bits/stdc++.h>
using namespace std;
int n[2000005],a,b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>n[i];
	}
	cout<<n;
	return 0;
}
