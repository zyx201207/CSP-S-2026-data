#include<bits/stdc++.h>
using namespace std;
long long a[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=-1,tot=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		if(tot==-1)tot=a[i];
		else tot&=a[i];
	}
	if(m==1)cout<<maxn;
	else cout<<tot;
	/*
	while(1+1==2){
		rp++;
		cout<<"rp++";
	}
	*/
	return 0;
}
