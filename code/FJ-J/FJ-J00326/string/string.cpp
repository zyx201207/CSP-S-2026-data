#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S,c;
	long long n,a,y=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			S+=c;
		}
	}
	long long  len=S.size();
	
	for(int i=len/2-1;i>=0;i--){
		if(S[i]!=S[len-i-1]){
			y++;
		}
	}

	cout<<y;
	return 0;
}	
