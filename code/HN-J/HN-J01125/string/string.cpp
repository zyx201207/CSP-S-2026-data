#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	int k=0;
    string w[200000];
	int b[200000];
	string c[200000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
	}
	for(int y=0;y<=n-1;y++){
		for(int h=0;h<=b[y]-1;h++){
			w[k]=c[y];
			k++;
		}
	}
	return 0;
}

