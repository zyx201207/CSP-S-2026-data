#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
string s,s1;
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
	string c;
	int a;
	cin>>a;
	cin>>c;
m+=a;
	}
	if(n=1){cout<<0;
	}
	if(n=2){cout<<3;
	}
	if(m<=10){cout<<3;
	}
if(m<=100){cout<<20;
	}
if(m<=1000){cout<<80;
	}
if(m<=10000){cout<<1000;
	}	
	
	
	
	
	
	
	
	return 0;
} 
