#include <bits/stdc++.h>
using namespace std;

long long a[1000000000];
char c[10000]; 
long long m;
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			S+=c[i];
		}
		m+=a[i];
 }
	int cnt=0;
	for(int j=0;j<=m/2;j++){
		if(S[j]!=S[m-j-1]) cnt++;
	}	



	return 0;
}
