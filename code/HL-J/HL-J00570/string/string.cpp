#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long c,z;
long long q[10000005];
long long h[10000000005],x[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		c+=a[i];
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=n;j++){
			for(int y=1;y<a[i];y++){
				cout<<x;
			}
		}
	}
	if(c%2==1){
		c=c/2+1;
		
	}
	else{
		z=c/2;
		
	}
	return 0;
}

