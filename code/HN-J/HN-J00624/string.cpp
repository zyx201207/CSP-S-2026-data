#include<iostream>
using namespace std;
int n,ans;
string l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			l+=b;
		}
	}
	int t=l.size();
	for(int i=0;i<=t/2;i++){
		if(l[i]!=l[t-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
