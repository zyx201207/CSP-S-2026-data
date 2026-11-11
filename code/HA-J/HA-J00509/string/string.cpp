#include<bits/stdc++.h>
using namespace std;
string s;
int t,num;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>num>>c;
		z+=num;
	}
	ans=z/2;
	cout<<ans;
}
