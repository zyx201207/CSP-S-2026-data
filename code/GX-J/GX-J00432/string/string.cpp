#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m[200000],g=1,c=1;
    string b[200000];
    cin>>n;
    for(int i=0;i<n;i++){
	    cin>>m[i]>>b[i];
	    if(i>0){
			if(m[i]==m[i-1]){
			    g++;
		    }
		    if(b[i]==b[i-1]){
			    c++;
		    }
		}
	}
	if(c==n){
		cout<<0;
		return 0;
	}
	if(g==n||g==n-1){
		cout<<m[0];
		return 0;
	}
}
