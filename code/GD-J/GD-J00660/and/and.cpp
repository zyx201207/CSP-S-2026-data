#include <bits/stdc++.h>
using namespace std;
int s[100005];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,a;
	cin>>n>>a;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n+1);
	int b;
	for(int i=0;i<a;i++){
		b+=s[n+i];
	}
	cout<<b;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
