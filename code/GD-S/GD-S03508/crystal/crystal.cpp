#include<iostream>
#include<algorithm>
using namespace std;
int n , ans , j;
long long m , A[500010];
unsigned long long B[500010] , C[500010];
inline int fmax(int x,int y){
	return (x<y)?y:x;
}
int func(int i){
	int l=1,r=i-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(C[i]-C[mid-1]-(mid-1)*(A[i]-A[mid-1]) > m){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>> n >> m;
	for(int i=1;i <= n;i++){
		cin>> A[i];
	}
	sort(A+1,A+n+1);
	for(int i=2;i <= n;i++){
		B[i]=A[i]-A[i-1];
		C[i]=C[i-1]+B[i]*(i-1);
	}
	for(int i=n;i >= 2;i--){
		j=func(i);
		ans=fmax(ans,i-j+1);
	}
	cout<< ans;
    return 0;
}
