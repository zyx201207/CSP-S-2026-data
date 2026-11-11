#include<bits/stdc++.h>
using namespace std;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long a[2100000000];
char b[2100000000];
void brt(int a[n],char b[n]){
	int x,y,z;
    for(int i=0; i<n; i++){
    	if(a[i]=2 and b[i]='a'){
    	    cout << "2";	
		}
		if(a[i]=2 and b[i]='b'){
    	    cout << "0";	
		}
	}	
}
int main(){
	long long n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> a[i];
		cin >> b[i];
	}
	brt(a,b);
			
	return  0;
}
