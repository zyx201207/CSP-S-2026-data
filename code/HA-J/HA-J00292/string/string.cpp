#include <bits/stdc++.h>
using namespace std;
int main(){
	int y=0,a=0;
	double n,s;
	string c,h[100005];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>s>>c;
		for(int j=1;j<=s;j++){
			h[a+1]=c;
			a++;
		}
	}
	for(int i=1;i<=(a%2==0?a/2:(a+1)/2);i++){
		if(h[i]!=h[a-i+1]){
			y++;
		}
	}
	cout<<y;
	return 0;
}
