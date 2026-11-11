#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],maxn=0;
int _and(int a,int b){
	int a2[30]={1},b2[30]={1};
	while(a){
		a2[a2[0]]=a%2;
		a/=2;
		a2[0]++;
	}while(b){
		b2[b2[0]]=b%2;
		b/=2;
		b2[0]++;
	}
	int c,len=min(a2[0],b2[0]);
	for(int i=1;i<len;i++){
		if(a2[i]=='1'&&b2[i]=='1') c=2*c+1;
		else c*=2;
	}
	return c;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int x=_and(a[i],a[j]);
			maxn=max(maxn,x);
		}
	}
	cout<<maxn;
	return 0;
} 
