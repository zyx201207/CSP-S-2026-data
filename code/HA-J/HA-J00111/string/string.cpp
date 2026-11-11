#include<bits/stdc++.h>
using namespace std;
long long a,b[1000010],cs;
char c[1000010];
string d;
void jc(string e){
	for(long long i=0;i<e.size()/2;i++){
		if(e[i]!=e[e.size()-i]){
		   e[e.size()-i]=e[i];	
		   cs++;
		} 
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>a;
    for(long long i=1;i<=a;i++){
    	cin>>b[i]>>c[i];
	}
	for(long long i=1;i<=a;i++){
    	for(long long j=1;j<=b[i];j++){
    		d+=c[i];
		}
	}
	jc(d);
	cout<<cs;
	return 0;	
}
