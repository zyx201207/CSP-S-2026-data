#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int max_1;
	cin>>n>>m;
	int b[n]={0};
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m=1){
		for(int i=0;i<n;i++){
			 max_1=max(max_1,a[i]);
		}
		cout<<max_1;
	}
	if(m=2){
	    for(int i=1;i<=(n-1)*(n-1)-1;i++){
		    b[i]=max(b[i],a[i]&a[i+1]);
	    }
	    cout<<b[m];
	}
	
	return 0;
}
