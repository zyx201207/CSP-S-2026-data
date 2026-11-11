#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[200005],l=0,n,eng=0;
	char s[200005];
	string z;
	cin>>n;
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		a[i]=c;
		cin>>s[i];
		l+=c;
	}
	for(int i=0;i<=l/2;i++){
	    int z,g;
	    long long b=0;
	    for(z=0;b<i;z++){
		b+=a[z];
	    }
	    b=l/2;
	    for(g=n/2;b<l-i;g++){
		b+=a[g];
	    }
		if(s[z]==s[g]) eng++;		
	}
	cout<<eng;
	return 0;
}
