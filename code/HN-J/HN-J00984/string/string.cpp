#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c[200005];
	int a[200005],n;
    string c1;
	long long s=0,x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
		for(int j=0;j<a[i];j++){
			c1+=c[i];
		}	
	}
	for(long long i=0;i<s;i++){
		if(c1[i]!=c1[s-1-i]){
		    x++;	
	    }
	}
	x/=2;
	cout<<x;
	return 0;
} 
