#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long l=n,a[n+1],c[m+1]={};
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n--){
		long long b[m+1]={};
		for(int i=l-n;i<=l;i++){
			if(b[a[i]] > 1){
				for(int j=1;j<=m;j++) b[j]=0;
			}else{
				b[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]) c[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}
