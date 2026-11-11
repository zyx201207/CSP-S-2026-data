#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out"."w",strout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	int k=0;
	for(int i=0;i<n;i++){
		if(b[i]!=b[i+1]){
			c[k++]=b[i];
		}
		b[i]=0;
	}
}
