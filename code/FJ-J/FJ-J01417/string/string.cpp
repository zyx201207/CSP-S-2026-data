#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int j=0,n,cha=0;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int k=0;k<n;k++){
		cin>>a[k]>>c[k];
	}
	while((n>=0)||(j<=n)){
		if(c[n]==c[j]){
			if(a[n]-a[j]>0){
				if(c[n]==c[j+1]){
					j++;
				}
				else{
					cha=cha+a[n]-a[j];
				}
			}
			else if(a[n]-a[j]<0){
				if(c[n-1]==c[j]){
				 	n--;
				}
				else{
					cha=cha+a[j]-a[n];
				}
			}
			else {
				n--;
				j++;
			}
	}
	cout<<cha;
	return 0;
}
