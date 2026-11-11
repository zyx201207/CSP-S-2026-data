#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string n,n1;
	long long b=0;
	int a=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b>>n1;
		for(int j=1;j<=b;j++){
			n+=n1;
		}
	}
	int t=0;
	for(int i=1;i<=n.length()/2;i++){
		if(n[i-1]!=n[n.length()-i]){
			t++;
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
