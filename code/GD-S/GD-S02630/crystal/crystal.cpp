#include<bits/stdc++.h>
using namespace std;
long long n,m,cy[500002]={0},cy2[500002]={0},cy3[500002]={0},l=1,r=0,mid=0,cy4[500002]={0},cy5[500002]={0};
bool two(long long a){
	for(int i=1;i<=n-a;i++){
		if((cy[i+a-1]-cy[1])*(a+i-1)-cy4[i+a]<=m){
			return true;
		}
	}return false;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	scanf("%ld %ld",&n,&m);
	r=n;
	for(int i=1;i<=n;i++){
		cin>>cy[i]; 
	}sort(cy+1,cy+1+n);
	for(int i=2;i<=n;i++){
		cy2[i]=cy[i]-cy[i-1];
		cy3[i]=(cy2[i])*(i-1);
		cy4[i]=cy3[i]+cy4[i-1];
	}
	while(l<=r){
		mid=(l+r)/2;
		if(two(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}printf("%ld",l-1);
	return 0;
} 
