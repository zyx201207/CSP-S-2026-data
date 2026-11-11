#include<bits/stdc++.h>
using namespace std;
long long n,a,q,e,v,h;
string c;
string s[20000005],x[10000005],y[10000005],w[2000005];
bool z=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		e+=a;
		for(long long j=0;j<a;j++){
			s[q]=c;
			q++;
		}
		w[i]=c;
	}for(long long i=1;i<n;i++){
		if(w[i]!=w[i-1]){
			z=1;
		}
	}
	if(z==0){
		cout<<0;
		return 0;
	}
	if(e%2==0){
	   for(long long i=0;i<e/2;i++){
		    x[i]=s[i];
	   }
	   for(long long i=e-1;i>e/2-1;i--){
		    y[h]=s[i];
		    h++;
	   }
	   for(long long i=0;i<e/2;i++){
		    if(x[i]!=y[i]){
			    v++;
		    }
	    }
	    cout<<v;
	}else{
	   for(long long i=0;i<e/2+1;i++){
		    x[i]=s[i];
	   }
	   for(long long i=e-1;i>e/2-1;i--){
		    y[h]=s[i];
		    h++;
	   }
	   for(long long i=0;i<e/2+1;i++){
		    if(x[i]!=y[i]){
			    v++;
	    	}
	    }
	    cout<<v;
	}
	return 0;	
}
