#include<bits/stdc++.h>
using namespace std;
int n,ss;
string s;
int a[100010];
char b[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)ss+=a[i];
	for(int i=1;i<=ss;i++){
		for(int j=1;j<=a[i];j++){
			s[i]=b[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
