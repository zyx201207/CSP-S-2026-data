#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,m;
long long a[1000001];
int mian(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(int i=0;i<=20;i++){
		cin>>a[i];
	}
	for(int i=0;i<=20;i++){
		if(a[i]==t+k) m++;
	}
	cout<<m;
	return 0;
}
