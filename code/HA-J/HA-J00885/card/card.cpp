#include<bits/stdc++.h>
using namespace std;
long long n,m,c,a[100005],b[100005],num[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>c;
	b[1]=c,a[1]=c;
	for(int i=2;i<=n;++i){
		cin>>c; 
		b[i]=c;
		a[i]=c;
		for(int j=1;j<=i;++j){
			if(c==b[j]){
				for(int k=1;k<=i;++k){
					b[k]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		num[b[i]]++;
		b[i]=a[i];
	}
	for(int i=1;i<=n;++i){
		cout<<num[i];
	}
	
} 
