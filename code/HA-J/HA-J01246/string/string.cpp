#include<bits/stdc++.h>
using namespace std;
char a[200009],l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long nn,s=0,cl=0;
	cin>>nn;
	while(nn--){
		int n,i=0;
		cin>>n;
		char o;
		cin>>o;
		while(n--){
			a[s]=o;
			s++;
		}
		i++;
	}
	for(int i=0;i<s/2;i++){
		int j=s-i-1;
		if(a[j]!=a[i]){
			cl++;
		}
	}

	
	cout<<cl;
	return 0;
}
