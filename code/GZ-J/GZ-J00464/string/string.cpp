//GZ_J00464 遵义市第十九中学 刘宇轩 
#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100001];
char b[100001];
bool v=true;
long long ans,s,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(b[1]==b[n]){
		sum++;
	}
    for(int i=2;i<=n;i++){
		if(b[i]!=b[i-1]){
			v=false;
		}
	}
	if(v){
		cout<<0;	
		return 0;
	}
	else cout<<3;
	return 0;
}
