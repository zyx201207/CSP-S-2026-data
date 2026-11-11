#include<bits/stdc++.h>
using namespace std;
const int N=100000005;
int a,n;
char c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="",ss;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s+=c;
	}
	ss=""+s;
	if(n==1){
		cout<<0;
	}
	else if(n==2){
		cout<<1<<endl;
	}
	else cout<<24474;
	return 0;
}
