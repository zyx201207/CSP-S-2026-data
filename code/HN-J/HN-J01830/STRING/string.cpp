#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long a[200005];
char c[200005];
int main(){
	//freopen("string.in","r","stdin");
	//freopen("string.out","w","stdout");
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		while(a[i]--){
			s[t]=c[i];
			t++;
		}
	}
	int sum=0;
	for(int i=0;i<=n/2;i++){
		if(s[i]!=s[n-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

