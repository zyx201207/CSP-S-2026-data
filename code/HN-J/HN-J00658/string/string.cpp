#include<bits/stdc++.h>
using namespace std;
long long T,t;
string a,b; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>t>>a;
		for(int i=0;i<t;i++){
			b+=a;
		}
	}
	long m=b.size();
	long long ans=0;
	for(int i=0;i<m;i++){
		if(b[i]!=b[m-i-1]) {
		b[i]=b[m-i-1];
		ans++;
	}
	}
	cout<<ans<<endl;
	return 0;
}

