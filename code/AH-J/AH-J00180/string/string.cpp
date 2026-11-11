#include<bits/stdc++.h>
using namespace std;
const int N=2e5+8,M=1e7;
struct node{
	long long a,l,r;
	char c;
}s[N];
char ans[M];
long long n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long f=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		s[i].l=f+1;
		s[i].r=f+s[i].a;
		f+=s[i].a;
		for(int j=s[i].l;j<=s[i].r;j++){
			ans[j]=s[i].c;
		}
	}
	int f1=f/2;
	if(f%2!=0) f1++;
	for(int i=1,j=f;i<=f1,j>=f1;i++,j--){
		if(ans[i]!=ans[j]) cnt++;
	}
	cout<<cnt;
	return 0;
}
