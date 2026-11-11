#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;  
ll boolf[100000][31]={};
ll num[100000]={};
void geter(ll w,ll k){
	ll temp[n]={};
	int i=0;
	while(w){
		temp[i]=w%2;
		w/=2;
	} 
	for(int j=0;i<i;j++){
		boolf[k][j]=temp[i-j];
	}
}
int main(){
	freopen("and.in","r",stdin);       
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll max_=-1111;
	for(int i=0;i<n;i++){
		cin>>num[i];
		max_=max(num[i],max_);
		geter(num[i],i);
	}
	cout<<max_;
	return 0;
}
