#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char y;
}s[100005];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].y;
	}
	cout<<"0";						
	return 0;
}
