#include <bits/stdc++.h>
using namespace std;
struct fff{
	long long x;
	char y;
}; 
fff a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0,da=0;
	cin >>n;
	for(int i=0 ; i<n ; i++){
		cin >>a[i].x>>a[i].y;
		s+=a[i].x;
	}
	int w=0,e=0,p=0,q=n-1;
	for(int i=0  ; i<s/2+1 ; i++){
		if(w>=a[e].x){
			e++;
			w=0;
		}
		if(p>=a[q].x){
			q--;
			p=0;
		}
		if(a[e].y!=a[q].y){
			da++;
		}
		w++;
		p++;
	}
	cout <<da;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
