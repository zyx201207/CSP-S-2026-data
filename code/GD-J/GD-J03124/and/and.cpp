#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int x,y;
    cin>>x>>y;
    int a[x+1];
    for(int i=0;i<x;i++){
    	cin>>a[i];
	}
	int max=0;
	 for(int i=0;i<x;i++){
    	if (a[i]>max);
    	max=a[i];
	}
	cout<<max;
    
    
}
