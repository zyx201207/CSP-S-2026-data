#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	long long a,b,d=1,e=1,f,g=0;
	cin>>a>>b;
	int c[a];
	for(long long i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	f=b;
	for(long long i=0;i<a-1;i++){
		if((i+1-g)*(c[i+1]-c[i])<=f){
			e++;
			f-=(i+1)*(c[i+1]-c[i]);
		}
		else{
			f+=abs(c[i]-c[g]);
			g++;
			i--;
			if(d<e)d=e;
			e--;
		}
	}
	if(d<e)d=e;
	cout<<d;
}
