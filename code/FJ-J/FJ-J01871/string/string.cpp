#include<bits/stdc++.h>
using namespace std;
long long n,a,b,d,s;
char c,x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		d=b+1;
		b+=a;
		for(int j=d;j<=b;j++){
			x[j]=c;
		}
	}
	for(int i=1;i<=b/2;i++){
		if(x[i]!=x[b-i+1]){
			s++;
		}
	}
	cout<<s;

	return 0;
}

