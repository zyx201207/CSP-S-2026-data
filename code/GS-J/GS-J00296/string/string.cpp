#include<bits/stdc++.h>
using namespace std;
int n,a,L,x,R;
string c,S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		L+=a;
		for(int j=1;j<=a;j++){
			S=S+c;
		}
	}
	x=L+1;
	x=x/2;
	for(int e=1;e<=x;e++){
		if(S[e-1]!=S[L+1-e-1]){
			R++;
		}
	}
	cout<<R;
	return 0;
}


