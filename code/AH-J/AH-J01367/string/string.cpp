#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int i=0;i<s.size();i++){
		    s[i]=c[i];
		    if(a[i]>1){
		    	s[i+a[i]-1]=c[i];
			}
	    }
	}
	for(int i=0;i<c.size();i++){
		if(c[c.size()/2]!=c[c.size()/2+1]){
			cout<<c.size()/2;
			break;
		}
	}
	cout<<s;
	return 0;
}
