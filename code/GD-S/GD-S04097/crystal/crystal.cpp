#include<bits/stdc++.h>
using namespace std;
int a[500010],n,m;
int check(int o,int l,int mid){
	int sum=0;
	for(int i=l;i<=mid;i++){
		sum+=a[i]-mid;
	}
	if(o==1){
		return sum;
	}
	int oo=l;
	while(sum<=m){
		sum-=a[oo];
		oo++;
	}
	else if(oo!=l){
		return oo;
	}else{
		return x;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];          
	}                       
	int l=1,r=n;
	while(l<r){
		int mid=l+(r-l)/2;
		if(check(0,l,mid)){
			l=mid;
		}else{
			r=mid+1;
		}
	}
	cout<<check(1)
	return 0;
} 
