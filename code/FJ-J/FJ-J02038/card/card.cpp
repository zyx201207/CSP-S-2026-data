#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[101010];
long long k[101010];
long long w[101010];
void zp(int x){
	long long t=0;
	for(int i=x;i<=n;i++){
		if(w[a[i]]==0){
			t++;
			w[a[i]]=t;
		}
		else {
			t++;
			for(int j=1;j<=t;j++){
				if(w[a[j]]>w[a[i]])w[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(w[i]!=0){
			k[i]++;
			w[i]=0;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)zp(i);
	for(int i=1;i<=m;i++)cout<<k[i]<<' ';
	return 0;
}
