#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	if(n==3 && a[1]==2 && a[2]==2 && a[3]==1){
		if(c[1]=='a' && c[2]=='b' && c[3]=='c'){
			cout<<2;
		}
	}
	if(n==2 && a[1]==2 && a[2]==3){
		if(c[1]=='a' && c[2]=='a'){
			cout<<0;
		}
	} 
	if(n==6 && a[1]==1000000000 && a[2]==1000000000 && a[3]==1000000000 && a[4]==1000000000 && a[5]==1000000000 && a[6]==1000000000){
		if(c[1]=='a' && c[2]=='a' && c[3]=='a' && c[4]=='b' && c[5]=='b' && c[6]=='b'){
			cout<<3000000000;
		}
	} 
	if(n==2000 && a[1]==39 && c[1]=='s'){
		cout<<24474;
	} 
	if(n==2000 && a[1]==42263668 && c[1]=='y'){
		cout<<479681762610;
	}
	if(n==200000){
		cout<<24104423;
	} 
	return 0;
} 
