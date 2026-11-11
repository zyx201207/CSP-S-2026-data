#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,q=0;
	long long w=0;
	cin>>a;
	long long s[a];
	char d[a];
	for(int i=0;i<a;i++){
		cin>>s[i]>>d[i];
		q+=s[i];
	}
	int n=a-1;
	if(q%2==1) q=(q-1)/2;
	else q/=2;
	int m=0;
	while(q>0){
		if(s[m]>q) s[m]=q;
		if(s[n]>q) s[n]=q;
		if(d[m]!=d[n]){
		    w+=min(s[m],s[n]);
	    }
	    q-=min(s[m],s[n]);
		if(s[m]>s[n]){
		    s[m]-=s[n];
		    n--;
	    }
	    else if(s[m]<s[n]){
	    	s[n]-=s[m];
	    	m++;
		}
		else{
			n--;
			m++;
		}
	}
	cout<<w;
	return 0;
}
