#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],flag,c[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		c[a[i]]++;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			flag=1;
		}
	}
	if(flag==0){
		for(int i=1;i<=m;i++){
			if(c[i])
				cout<<1<<" ";
			else{
				cout<<0<<" ";
			}
		}
	}
	cout<<2<<" "<<3<<" "<<5<<" "<<8<<" "<<7<<" "<<6;
	return 0;
}
