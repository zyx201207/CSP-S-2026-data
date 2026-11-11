#include<bits/stdc++.h>
using namespace std;
long long  n,m,mid,cnt=0;
bool flag=1;
int a[1000100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)  flag=0;
	}
	    if(n%2!=0){
		 mid=(n+1)/2;
	}else{
		mid=n/2;
	}
	   sort(a+1,a+n+1);
		
		    for(int j=1;a[j]<=mid&&m!=0;j++){
		    	m=-(a[mid]-a[j]);
		    	a[j]=a[mid];
		    	cnt++;
		    	
			}
			
			cout<<cnt;
	 


	return 0;
}

