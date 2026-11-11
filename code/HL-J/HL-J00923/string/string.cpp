#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,m;
	long long c=0,n,b;
	cin>>n;
	cin>>b>>m;
	a=m;
	for(int j=0;j<b-1;j++){
    		a+=m;
    for(int i=0;i<n-1;i++){
	}
    	cin>>b>>m;
    	for(int j=0;j<b;j++){
    		a+=m;
		}
	}
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1]) c++;
	}
	cout<<c;
	return 0;
}