#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b;
	long long cnt=0; 
	cin>>a;
	string c="",d="";
	for(int x=0;x<a;x++){
		cin>>b>>c;
		for(int y=0;y<b;y++){
			d+=c;
		}
	}for(long long x=0,x2=d.length()-1;x<(d.length()+1)/2,x2>=(d.length()+1)/2;x++,x2--){
		if(d[x]!=d[x2]) cnt++;
	}cout<<cnt;
	return 0;
}
