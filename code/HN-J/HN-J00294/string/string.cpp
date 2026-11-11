#include<bits/stdc++.h>
using namespace std;
char z[100005];
char len1[500005];
char len2[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    char b; 
    int s,a,len=0,f=0,sum=0;
    cin>>s;
    for(int i=1;i<=s;i++){
    	cin>>a;
    	cin>>b;
    	for(int j=1;j<=1;j++){
    		z[j+len]=b;
		}
		len=len+a;
	}for(int i=1;i<=len/2;i++){
		if(z[1]==z[len]){
		sum++;
		}
		if(z[i]!=z[len+2-1]){
		sum++;
		}
	}
	cout<<sum;
	} 
	

    
