#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long a,b[10000],x=1,e=0;
	char c[10000];
	string d;
	cin >> a;
	for(int i=0;i<a;i++){
		cin >> b[i] >> c[i];
		for(int j=x;j<=b[i];j++){
			d[j]=c[i];
		}
		x=x+b[i];	
	}
	x--;
	if(x%2 == 0){
		a=x/2;
		for(int i=0;i<a;i++){
			if(d[a-i] != d[a+i+1]){
			    e++;
		    }
	    }
	}
	return 0;
}
