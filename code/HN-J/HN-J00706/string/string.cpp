#include<bits/stdc++.h>

using namespace std;

int main(){

	freopen("string.in.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x[10005];
	string s;
	cin>>n;
	int a=0,q=0,a1;
	int qwe=0;
	
	for(int j=1;j<=n;j++){
		
		int b;
		cin>>b;
		a=a+b;
		x[j]=b;
		qwe++;
		a1=b;
	
		
		char c;
		cin>>c;
		
		for(int i=q;i<a;i++){
			s[i]=c;
			q++;
		}
	}

	
	sort(x+1,x+qwe+1);
	
	if(x[0]==x[qwe]){
		if(n*a1%2==1){
			cout<<a1*(n/2);
		}else{
			cout<<a1*n/2;
		}
	}
	else if(n==1){
		cout<<0;
		return 0;
	}else{
		cout<<a1*n/3;
	}
	
	
	
	
	return 0;
} 
