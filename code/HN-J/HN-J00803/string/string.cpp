#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("strint.in","r",stdout);
	long long n,x[50050],m[50050],q=0;
	char y[5050];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		q+=x[i];
	}
		for(int i=1;i<=n;i++){
				q-=x[i];	
		}
	cout<<q+2;
}
