#include<bits/stdc++.h>
using namespace std;



int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int n,m,v=0,u=0,r=0;
    double w=0;
    char a[10];
    char b[10];
	cin >> n;
	
	for(int i=1;i<=3;i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i=1;i<=3;i++){
		cin >> b[i];
	}
	if(n==m){
		v=1;
	}
	if(v==1){
		if(a[1]==b[1]&&a[2]==b[2]){
	        u=1;
	    }
	}
	
	if(v==1&&u==1){
		if(a[1]==b[1]&&a[2]==b[2]){
		    w+=0.5;
	    }
	}
	if((int(a[3])<=67&&int(b[3])<=67)||int(a[3])>=68&&int(b[3])>=68){
		w+=0.5;
	}
	if(w==0.5){
		w=0;
	}
	if(v==1&&u==1&&w==1){
		if(a[3]=='A'&&b[3]=='B'){
		    r=1;
	    }
	    if(a[3]=='B'&&b[3]=='C'){
		    r=1;
	    }
	    if(a[3]=='D'&&b[3]=='F'){
		    r=1;
	    }
	    if(b[3]=='A'&&a[3]=='B'){
		    r=1;
	    }
	    if(b[3]=='B'&&a[3]=='C'){
		    r=1;
	    }
	    if(b[3]=='D'&&a[3]=='F'){
		    r=1;
	    }
	}
	else{
		r=0;
	}
	cout << v << u << w << r;
	
	return 0;
}
