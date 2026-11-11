#include<bits\stdc++.h>
using namespace std;
string s;
long long n,a,h=0;
char c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=n;j++){
			s+=c;
		}
		h+=a;
	}
	if(h%2==0){
		cout<<h/2;
	}else{
		cout<<(h-1)/2;
	}
	return 0;
}
