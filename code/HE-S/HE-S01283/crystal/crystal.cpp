#include<bits/stdc++.h>
using namespace std;
int a[5005],n,m; 
int main(){
	freopen("crystal","r","crystal.in");
	freopen("crystal","w","crystal.out");
    int num=0;
    cin>>n>>m;
    for(int i;i<=n;i++){
    	cin>>a[i];
	    num++;
	}
	cout<<num;
	
 
    return 0;
} 
