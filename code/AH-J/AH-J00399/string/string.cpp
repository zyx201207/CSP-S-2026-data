#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int d[21111];
char k[21111];
int main(){
	freeopen("string.in","r",stdin);
    freeopen("string.out","w",stdout);
	int n,c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i]>>k[i];
			for(int j=1;j<=d[i];j++){
				a+=k[i];
			}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=d[i];j++){
			b+=k[i];
		}
	}
	for(int i=1;i<=a.size()/2;i++){
		if(a[0]!=b[0]){
			c++;
		}
	}
	cout<<c;
	return 0;
}
