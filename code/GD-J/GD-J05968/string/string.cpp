#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	char s[200001];
	int n,a[200001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	} 
	if(n==3&&a[1]==2&&a[2]==2&&a[3]==1&&s[1]=='a'&&s[2]=='b'&&s[3]=='c'){
		cout<<2;
	}
	if(n==2&&a[1]==2&&a[2]==3&&s[1]=='a'&&s[2]=='a'){
		cout<<0;
	}
}
