#include<bits/stdc++.h>
using namespace std;
int a[200005];
/*int bi(int x){
	int l=0,r=31;
	int mid=(l+r)/2;
	int g=0;
	while(x!=0){
		mid=(l+r)/2;
		if(x=pow(2,mid)){
			g=1;
			break;
		}
		else if(x<=pow(2,mid))r=mid;
		else if(x>pow(2,mid)&&x<pow(2,mid+1))break;
		else l=mid+1;
	}
	if(g==1)return mid;
	return mid+1;
}*/
/*int jiex(int x){
	int ji=1;
	while(x!=0){
		ji*=x;
		x-=1;
	}
	return ji;
}*/
/*int u(int x){
	if(u=1){
		sort(a+1,a+n+1);
		return a[n];
	}
	
}*/
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;//jiex(n)/(jie(m)*jie(m))
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-1000;
	for(int i=1;i<=n;i++){
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	cout<<maxn;
	return 0;
}
