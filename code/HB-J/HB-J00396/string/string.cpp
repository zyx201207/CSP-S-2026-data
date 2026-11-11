#include<bits/stdc++.h>
using namespace std;
int n,a[99999999],sum=0,l=0,t=0;
char S[99999999],c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i]>>c;
	    for(int j=0;j<a[i];j++){
		    S[t]=c;
		    t++;	
		}	
	}
	for(int i=0;i<t;i++){
	    if(S[i]==S[t-i]){
		    l=1;    	
		}
		else{
			l=0;
		    sum++;
		}
	}
	if(l==1){
		cout<<0;
	}
	else{
		cout<<sum-1;
	}
}
