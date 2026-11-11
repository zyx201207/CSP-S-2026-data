#include<bits/stdc++.h>
using namespace std;
bool change(string x){
	string y="";
	for(int i=x.size()-1;i>=0;i--){
	y+=x[i];	
	}
	if(x==y){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,j,g;
    char e,r;
    string s="";
    cin>>n;    
    for(int i=1;i<=n;i++){
    	int a;
    	char b;
    	cin>>a>>b;
    	if(i==1){
    		j=a;
    		e=b;
    	}
    	if(i==2){
    		g=a;
    		r=b;
    	}
    for(int j=1;j<=a;j++){
    	s+=b;
    }
    }
    if(n==1){
    	cout<<0;
    	return 0;
    }
    if(n==2&&e!=r){
    	cout<<min(j,g);
    	return 0;
    }
    if(change(s)==1){
    	cout<<0;
    	return 0;
    }
	int sum=0;  
   		for(int i=0;i<s.size();i++){
   		if(s[i]!=s[s.size()-1-i]){
   			s[s.size()-1-i]=s[i];
   			sum++;
   		}	
   		}  
   cout<<sum;
return 0;
}
