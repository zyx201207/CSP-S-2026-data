#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100100][100100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int g=0;g<=n;g++){
			cin>>a[i][g];
		}
	}
	int s==0;
	for(int j=1;i<=n%2;i++){
		if(a[1+n/2]!=a[n/2]){
			s++;
		}
	}
	cout<<s;
	return 0;
}
