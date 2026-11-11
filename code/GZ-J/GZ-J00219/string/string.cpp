//GZ-S00219   ÅíìÏºã 
#include <bits/stdc++.h>
using namespace std;
    int a,b;
    long long z;
	char s;
	string d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>a;
	int ss[a+1];
	for(int i=0;i<a;i++){
		cin>>b>>s;
		for(int i=0;i<b;i++){
			d+=s;
		}
		
	}
	for(int i=0;i<d.size()-1;i++){
		if(d[i]!=d[d.size()-1]){
			z++;
		}
	}
	cout<<z/2;
	fclose(stdin);
	fclose(stdout);
}

