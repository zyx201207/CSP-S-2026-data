#include<bits/stdc++.h>
using namespace std;
struct st{
	long long a;
	char c;
}s[200005];
char cx[100000000];
long long n,m,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		for(int j=1;j<=s[i].a;j++){
			cx[m+j]=s[i].c;
		}
		m+=s[i].a;
	}
	for(int i=1,j=m;i<=j;i++,j--){
		if(cx[i]!=cx[j])cnt++;
	}
	cout<<cnt;
	return 0;
}
