#include<bits/stdc++.h>
using namespace std;
int n,a[200020];
char c;
bool fl=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
	}
	int x;
	string s;
	while(x--){
		s=n+c;
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			fl=0;
		}
		if(fl==1){
			true;
		}
		cout<<fl;
	}
	return 0;
}