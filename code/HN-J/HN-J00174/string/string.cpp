#include<bits/stdc++.h>
using namespace std;
string x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long a;
    char c;
    cin>>n;
    int y=0;
    for(int i=1;i<=n;i++){
    	cin>>a;
    	cin>>c;
    	for(int j=y;j<y+a;j++){
    		x[j]=c;
    		y+=a;
		}
	}
	
	int s=0;
		for(int i=0;i<x.length();i++){
		    if(x[i]!=x[x.length()-i]){
		    	s++;
			}	
		}		
	cout<<s;
	return 0;
} 
