#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n;//a&b
int a[200005];
char c[200005];
string s;
int main(){
	//ignore
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cin.ignore();
		cin>>c[i];
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=a[i];++j){
			s+=c[i];
		}
	}
	//cout<<s;
	int ab=s.size();
	for(int i=0;i<=ab/2;++i){
		if(s[i]!=s[ab-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
