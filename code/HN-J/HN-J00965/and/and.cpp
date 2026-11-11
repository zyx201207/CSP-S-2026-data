#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,l;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
	    for(int i=0;i<n;i++){
		    if(a[i+1]>a[i]){
		       l=a[i];
			   a[i]=a[i+1];
			   a[i+1]=l;
		}
	}
}
    cout<<a[m-1];
	return 0;
} 
