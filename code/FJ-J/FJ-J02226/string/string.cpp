#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[200005];
	int c=0;
	char b[200005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	char a1=b[0];
	for(int i=0;i<n;i++){
		if(b[i]!=a1){
			return 0;
		}
	}
	cout<<0;
	return 0;
}
