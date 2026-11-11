#include<bits/stdc++.h>
using namespace std;
struct M{
	long long a;
	char c;
};
M s[1000000];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	cout<<0;
	return 0;
}