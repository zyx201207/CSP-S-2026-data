#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n=0,cnt=0;
	int a[100000];
	string b[100000];
	cin>>n;
	for(int i=0;i<n;i++){
		 cin>>a[i];
		 cin>>b[i];
	}
	for(int i=0;i<n;i++){
		if(b[i]!=b[i+1]){
			cnt+=a[i];
		}
	}
	cout<<cnt;
	return 0;
}
