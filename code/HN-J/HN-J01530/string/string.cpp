#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,number=0;
	cin>>n;
	int a[200005];
	char c[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];cin>>c[i];}
	for(int i=0;i<n;i++){
		number+=a[i];}
	int b[number+5],d=0,e=a[0];
	for(int i=1;i<=number;i++){
        b[i]==c[d];
        if(i==e){
        	d++;
        	e+=a[d];
		}
	}
	d=0;
	char z[200005+5];
	for(int i=1;i<=(number+1)/2+1;i++){
		z[i]=c[number+1-i];	}
	for(int i=1;i<=(number+1)/2+1;i++){
		if(z[i] != c[i]){
		d+=1;}
	}
	cout<<d-1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
