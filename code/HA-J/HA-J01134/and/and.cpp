#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k,h;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		    if(a[j]<a[j+1]){
		        k=a[j];
		        a[j]=a[j+1];
		        a[j+1]=k;
		    }
		}
	}
	for(int i=0;i<m;i++){
		if(i==0)
		    h=a[i];
		else
		    h=h&a[i];
	}
	cout<<h;
	return 0;
}
