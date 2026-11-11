#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[n+10];
	int b[n+10];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		b[i]=a[i]&a[i+1];
	}

	

		for(int i=0;i<n/2;i++){
			if(b[i]>=b[i+1]){
				b[i]=b[i];
			}
			else{
				b[i]=b[i+1];
			}
			
		}
		

	
	cout<<b[0];
	
	return 0;
}
