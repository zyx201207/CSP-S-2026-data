#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N],s[N],k;
int b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	k=0;
	for(int i=1;i<=n;i++){
		k+=1;
		s[k]=a[i];
		if(b[s[k]]!=0)k=b[s[k]];
		else b[s[k]]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<n-b[i]<<" ";
	}
	return 0;
} 
