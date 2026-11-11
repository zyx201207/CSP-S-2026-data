#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    string c;
    string x;
    string a;
    cin>>s>>c>>x>>a;
    if (s[1]==x[1] && s[2]==x[2]){
        cout<<1;
    }
    else{
    	cout<<0;
	}
	
	if (c[0]==a[0] && c[1]==a[1]){
		cout<<1;
	}
	else{
		cout<<0;
	} 
	
	if (c[0]==a[0] && c[1]==a[1] && c[2]=='A' && a[2]=='B'){
		cout<<1;
	}
	else if (c[0]==a[0] && c[1]==a[1] && c[2]=='A' && a[2]=='C'){
		cout<<1;
	}
	else if (c[0]==a[0] && c[1]==a[1] && c[2]=='B' && a[2]=='C'){
		cout<<1;
	}
	else if (c[0]==a[0] && c[1]==a[1] && c[2]=='D' && a[2]=='F'){
		cout<<1;
	}
	else if (c[0]==a[0] && c[1]==a[1] && c[2]=='B' && a[2]=='A'){
		cout<<1;
    }
    else if (c[0]==a[0] && c[1]==a[1] && c[2]=='C' && a[2]=='A'){
		cout<<1;
    }
    else if (c[0]==a[0] && c[1]==a[1] && c[2]=='C' && a[2]=='B'){
		cout<<1;
    }
    else if (c[0]==a[0] && c[1]==a[1] && c[2]=='F' && a[2]=='D'){
		cout<<1;
    }
	else{
		cout<<0;
	}
	
	if (c[0]==a[0] && c[1]==a[1] && c[2]=='A' && a[2]=='B' && s[1]==x[1] && s[2]==x[2]){
		cout<<1;
	}
	else if (c[0]==a[0] && c[1]==a[1] && c[2]=='A' && a[2]=='C' && s[1]==x[1] && s[2]==x[2]){
		cout<<1;
	}
	else if (c[0]==a[0] && c[1]==a[1] && c[2]=='B' && a[2]=='C' && s[1]==x[1] && s[2]==x[2]){
		cout<<1;
	}
	else if (c[0]==a[0] && c[1]==a[1] && c[2]=='D' && a[2]=='F' && s[1]==x[1] && s[2]==x[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
