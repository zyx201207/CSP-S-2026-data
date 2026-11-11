#include<bits/stdc++.h>
using namespace std;
long long q,w,e,r,l,a[501000],b[501000],c[301000],d[301000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>q>>w;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	for(int i=q;i>=1;i--){
		b[i]=c[a[i]];
		c[a[i]]=i;
	}
	for(int i=1;i<=q;i++){
		for(int j=i;j<=q;j++){
			while(b[j]!=0){
				j=b[j];
			}
			d[a[j]]++;
		}
	}
	for(int i=1;i<=w;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
