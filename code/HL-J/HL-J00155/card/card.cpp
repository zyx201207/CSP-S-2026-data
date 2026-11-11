#include<bits/stdc++.h>
using namespace std;
int main (){
long long a[10005],n,m,b,sum=0;
freopen("card.in","r",stdin);
freopen("card.in","r",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	b+=a[i];
	if(b==m) cout<<a[i]-b;
}
return 0;
}

