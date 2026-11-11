#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int fcd;
char c[100005];
string s,sn1,sn2;
bool bol;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			bol=true;
		}
		else{
			bol=false;
		}
//		for(int j=1;j<=a;j++){
//			s+=c;
	}
	for(int i=2;i<=n;i++){
		if(c[i]==c[i-1]){
			bol=true;
		}
		else{
			bol=false;
		}
	}
//	}
//	int cd=s.size();
//	fcd=floor(cd/2);
//	if(cd%2==0){
//		for(int i=1;i<=cd/2;i++){
	//		sn1+=s[i];
	//	}
	//	for(int i=n;i<=cd/2+1;i--){
	//		sn2+=s[i];
	//	}
	//}
//	if(sn1==sn2){
	//	cout<<0;
//	}
	if(bol==true){
		cout<<0;
	}
	return 0;
}
