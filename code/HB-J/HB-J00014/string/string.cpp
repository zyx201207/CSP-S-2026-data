#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],x,h=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0,j=n-1;i<=j;){
		if(c[j]==c[i]){
			x=0;
		}
		else x=1;
		if(a[i]>a[j]){
	    	a[i]-=a[j],h+=a[j]*x,j--;
		}
		else if(a[i]<a[j]){
			a[j]-=a[i],h+=a[i]*x,i++;
		}
		else j--,i++,h+=a[i]*x;
	}
	cout<<h;
	return 0;
}
