#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    long long a,t=0,sd=0,l;
    string s,d;
    for(long long i=0;i<n;i++){
    	cin>>a>>s;
    	l=a;
    	for(int j=0;j<a;j++){
    		d+=s;
		}
	}
	string z;
	z=d;
	sd=d.size();
	reverse(d.begin(),d.end());
	for(long long i=0;i<sd;i++){
		if(z[i]!=d[i])t++;
		else{
			cout<<t;
			break;
		}
	}
	if(t==sd){
		cout<<sd-l;
	}
	return 0;
}
