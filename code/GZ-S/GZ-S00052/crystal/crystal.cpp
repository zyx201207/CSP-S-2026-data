//GZ-S00052    黄福恩    遵义市播州区实验学校 
#include <bits/stdc++.h>
using namespace std;
int n,m,c;
int a[500000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	c=0;
	for(int i=n/2;i<=0;i--){
		if(c*a[0]/a[1]+a[0]/a[1]>=m){
			c+=a[0]/a[1];
			m-=c*a[0]/a[1]+a[0]/a[1];
		}
	}
	for(int i=0;i<c;i--){
		for(int j=0;j<i;j++){
			for(int k=0;k<a[0]/a[1];k++){
				a[j]++;
			}
		}
	}
	for(int i=0;i<c;i++){
		cout<<a[i]; 
	}
}

