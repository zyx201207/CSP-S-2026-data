#include<bits/stdc++.h>
int const N=1e6+10;
long long a[N],s[N],c,t,n,d,maxx=0,num=0;
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		num=0;
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>a[i]>>s[i];
		num++;
		maxx=max(maxx,num);
		cout<<d-1;
	}
	return 0;}

