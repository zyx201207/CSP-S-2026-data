#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100],c[100],b[1000],m=0,g=0,d=0,q=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q++;
    }
    for(int j=1;j<=a[q];j++){
			b[j]=c[q];
			m++;
		    g++;
	    }
	for(int s=1;s<=m;s++){
		if(b[s]==!b[g]){
			d++;
			g--;
		}
	}
	cout<<d;
	return 0;
}
