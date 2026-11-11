#include<bits/stdc++.h>
using namespace std;
const int MAX=500000;
int arr[MAX];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,i,j,k;
    long long m;
    int o;
    int a=0,b=0,c=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
    	cin>>arr[i];
	}
	sort(arr,arr+n);
	if(n%2!=0){
		o=n/2;	
		for(k=0;k<m;k++){
		a=arr[o]-arr[k];
		b=a+b;
		if(b<m){
			c++;
		}
	}
	cout<<c;
		}
	else{
		for(k=0;k<m;k++){
			a=arr[n-1]-arr[k];
			b=a+b;
			if(b<=m){
				c++;
			}	
		}
		cout<<c;
	}	

    fclose(stdin);
    fclose(stdout);
    return 0;
}

