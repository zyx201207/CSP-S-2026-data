#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;
int a[MAX],n,m,tal;
bool cmp(int a,int b){
	int a1=0,b1=0;
	while(a>0){
		if(a%2)
		a1++;
		a>>=1;
	}
	while(b>0){
		if(b%2)
		b1++;
		b>>=1;
	}
	return a1>b1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	tal=a[0];
	for(int i=1;i<m;i++){
		tal=tal & a[i];
	}
	cout<<tal;
	return 0;
} 
