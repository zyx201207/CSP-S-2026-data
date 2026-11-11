#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("and.in","r","stdin")
    freopen("and.out","w","stdout")
    long long n,m;
    cin>>n>>m;
	long long x=0;
    for(int i=1;i<=m;i++){
		if(a[i]>a[i+1]){
	        x=a[i+1];
		}else{
		    x=a[i];
		}
	}cout<<x;    
	return 0;
}

