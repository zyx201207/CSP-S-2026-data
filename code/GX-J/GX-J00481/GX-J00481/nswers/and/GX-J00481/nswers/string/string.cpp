#include <bits/stdc++.h>
using namespace std;
string S;
long long n,a,cnt=0,b[100000005];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		b[i]=a; 
		for(int j=1;j<=a;j++){
			S+=c;
		}
	}
	
	for(int i=1;i<=a*c;i++){
		if(S[i]!=S[a*c-i+1]){
			if(b[i]>1)cnt++;
			}
	}
	cout<<cnt;
	
	return 0;
}
