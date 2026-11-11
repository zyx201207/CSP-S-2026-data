#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
int ans=0,a[N],zl[N],zld;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
			cin>>a[i]>>s[i];
			zl[i]=zl[i-1]+a[i];
	}
	zld=zl[n];
	for(int i=1;i<=n;i++){
		cout<<s[i];
	}
	return 0;
}
