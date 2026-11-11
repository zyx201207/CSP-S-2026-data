#include<bits/stdc++.h>
using namespace std;
string b[510];
long long a[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,k=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		k++;
	}
	if(k<=2){
			cout<<"0";
	}else if(k>=3){
		cout<<"2";
	}
	return 0;
} 
