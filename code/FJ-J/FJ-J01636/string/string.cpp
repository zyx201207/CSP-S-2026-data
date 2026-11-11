#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string k;
	for(int i=1;i<=n;i++){
		int a;
		char s;
		cin>>a>>s;
		for(int i=1;i<=a;i++){
			k+=s;
		}
	}
	int sum=0;
	for(int i=0;i<=k.size()/2;i++){
		if(k[i]!=k[k.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
}
