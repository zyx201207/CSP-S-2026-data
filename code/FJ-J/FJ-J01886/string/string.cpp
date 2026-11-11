#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,s,d,f,g,h,j,k=0,l=0;
	string z,x,c;
	cin>>a;
	for(s=0;s<a;s++){
		cin>>d>>x;
		for(g=0;g<d;g++){
			z=z+x;
		}
	}
	j=z.size()-1;
	for(h=0;h<z.size()/2;h++){
		if(z[h]!=z[j]){
			l=l+1;
		}
		j=j-1;
	}
	cout<<l;
	return 0;
}
