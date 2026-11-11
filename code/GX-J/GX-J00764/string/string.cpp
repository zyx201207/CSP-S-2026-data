#include<bits/stdc++.h>
using namespace std;
char h,l[500000000],r[500000000],c[1000000000];
int n,xb,ans;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		int a=0;
		char t;
		cin >> a >> t;
		while(a--){
			c[xb]=t;
			xb++;
	    }	
    }	
    if(xb%2==1){
		int b=(xb/2)-1;
		h=c[b];
		for(int i=0;i<=b;i++){
			l[i]=c[i];
	    }	
	    for(int i=0,j=xb-1;i<=b;i++,j--){
			r[i]=c[j];
	    }	
	    for(int i=0;i<=b;i++){
			if(r[i]!=l[i]){
				ans++;
		    }	
	    }	
	    cout << ans;
	    return 0;
    }		
    else if(xb%2==0){
		int b=xb/2;
		for(int i=0;i<=b;i++){
			l[i]=c[i];
	    }	
	    for(int i=0,j=xb-1;i<=b;i++,j--){
			r[i]=c[j];
	    }	
	    for(int i=0;i<=b;i++){
			if(r[i]!=l[i]){
				ans++;
		    }	
	    }	
	    cout << ans;
	    return 0;
    }	
    return 0;
}
