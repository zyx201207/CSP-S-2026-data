#include<bits/stdc++.h>
using namespace std;

string a;

int www(){
	
	string h;
	for(int i=a.size()-1;i>=0;i--){
		h+=a[i];
	}
	int k=a.size()/2,n=0;
	for(int i=0;i<k;i++){
		if(a[i]!=h[i]) n++;
	}
	return n;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n;
	char g;
	cin>>n;
	for(int i=1,j;i<=n;i++){
		cin>>j>>g;
		for(int x=1;x<=j;x++){
			a+=g;
		}
	}
	cout<<www();
}
