#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,c[10000005],d[10000005],e[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		if(d[c[i]]==1) for(int j=e[c[i]]+1;j<=i;j++) d[c[j]]--;
		d[c[i]]++;
		e[c[i]]=i;
	}
	if(b==1) cout<<a/2+a%2;
	return 0;
}
