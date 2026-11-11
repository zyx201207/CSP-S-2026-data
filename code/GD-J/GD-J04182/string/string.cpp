#include<bits/stdc++.h> 
using namespace std;
char s[1000010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    int n,k,t=0,cn=0;
    char a;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>k>>a;
    	for(long long q=1;q<=k;q++){
    		t++;
    		s[t]=a;
		}
	}
	int w,ww,x,xx;
  if(n==1){
  	cout<<"0"<<endl;
  }else{
  	if(t%2==0){
  		ww=t+1;
  		w=ww/2;
  		if(s[w+1]!=s[w]){
  			cn++;
  			s[w+1]=s[w];
		  }
		  for(int i=1;i<w;i++){
		  	if(s[ww-i]!=s[i]){
		  		cn++;
			  }
		  }
	  }
	  
	  if(t%2!=0){
	  	xx=t+1;
	  	x=xx/2;
	  	for(int q=1;q<x;q++){
	  		if(s[q]!=s[xx-q]){
	  			cn++;
			  }
		  }
	  }
  }
  cout<<cn<<endl;
	return 0;
}
