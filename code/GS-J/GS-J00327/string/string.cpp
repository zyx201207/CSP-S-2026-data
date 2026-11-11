#include<bits/stdc++.h>
using namespace std;
int n;
long long w=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char s,q[2][n];
	for(int i=0;i<n;i++){
		cin>>q[0][i];
		cin>>q[1][i];
	}
	int y=1;
	for(int i=0;i<n;i++){
		if(q[0][i]!=q[0][n-i]){
			y=0;
			break;
		}
	}
	if(y==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(q[0][i]!=q[0][n-i]){
			w++;
		}
	}
	cout<<w;
	return 0;
}
