#include<iostream>
using namespace std;
void f(){
	int n,m,a[2005][21];
	cin>>n;
	for(int i=0;i<n;i++){
		int x,j=0;
		cin>>x;
		while(x>0){
			if(x%2==1) a[i][j]=1;
			x/=2;
		}
	}
	for(int i=0;i<21;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(a[i][j]>0){
			    cnt++;
			}
		}
		if(cnt>=m){
			;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	f();
	return 0;
}
