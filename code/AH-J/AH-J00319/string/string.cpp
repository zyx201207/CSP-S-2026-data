#include<bits/stdc++.h>
using namespace std;
int n,a,t=1,d,v,l;
string b[200000];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		d=d+a;
		t=t+a;
		for(int j=t;j<=a;j++){
			b[j]=c;
		}
	}
	int l=d-1;
	for(int i=1;i<=d;i++){
		if(b[i]!=b[l+i]) v++;
		l=l-2;
	}
	cout<<v;
}
