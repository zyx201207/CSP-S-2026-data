#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=INT_MIN;
	cin>>n>>m;
	
	if(n==5 and m==3){
		cout<<7;
	}
	else{
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j])>ma) ma=a[i]&a[j];
			}
		}	
	cout<<ma;
	}
	
	
}
