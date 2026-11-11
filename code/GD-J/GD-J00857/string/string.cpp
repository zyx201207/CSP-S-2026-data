#include<bits/stdc++.h>
using namespace std;
char S[100005]={0},n,a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++)S[strlen(S)-1]=b;
	}
	for(int i=0;i<n;i++){
		cout<<S[i];
	}
	return 0;
}
