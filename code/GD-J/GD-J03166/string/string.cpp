#include<bits/stdc++.h>
using namespace std;
char a[200005],e[2000005];
long long b[200005],o,n;
bool k=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		for(int j=1;j<=b[i];j++){
			e[o]=a[i];
			o++;
		}
}
	for(int i=0;i<o-1;i++){
		if(e[i]!=e[o-i-1]){
			k=false;
			break;
		}
	}
	if(k==true){
		cout<<0;
		return 0;
	}
	else{
		cout<<min(b[1],b[2]);
		return 0;
	}
	return 0;
}
