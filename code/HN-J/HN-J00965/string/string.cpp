#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	int x=0,y=0,z=0;
	for(int i=0;i<n;i++){
		int a;
	    char c;
	    cin>>a>>c;
		x+=a;
		for(int i=y;i<x;i++){
			s[i]=c;
		}
		y+=a;
	}
	y--;
	if(x%2==0){
	for(int i=0;i<=x/2;i++){
	    for(int j=y;j>=x/2;j--){
	    	if(s[i]!=s[j]) {
	    		z++;
			}
		}	
	}
}else{
	for(int i=0;i<=(x/2);i++){
	    for(int j=y;j>=(x/2);j--){
	    	if(s[i]!=s[j]) {
	    		z++;
			}
		}	
	}
}
	cout<<z/3;
	return 0;
} 
