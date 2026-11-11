#include<iostream>
using namespace std;
int a[200000];
char c[200000];
int hw(int l,int r){
	int sum=a[l],sumr=a[r];
	r--;
	l++;
	while(l<r){
		if(sum>sumr){
			sumr+=a[r];
			r--;
		}
		sum+=a[l];
		l++;
	}
	return sum;
}
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n-i;i++){
		if(c[i]!=c[n-i]){
			cout<<hw(i,n-i)<<' ';
		}
	}
	return 0;
} 
