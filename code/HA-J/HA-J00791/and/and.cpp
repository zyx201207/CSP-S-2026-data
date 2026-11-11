#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
   	int m,n;
   	cin>>n>>m;
   	for(int i=0;i<n;i++){
   		cin>>a[i];	
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0];
		return 0;
	}
		
	if(m==n){
		for(int i=0;i<n;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[n-1];
		return 0;
	}
	else if(m==n-1){
		for(int i=0;i<n-1;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[n-2];
		return 0;
	}
	else{
		for(int i=0;i<m;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[m-1];
		return 0;
	}

		
	return 0;
} 
