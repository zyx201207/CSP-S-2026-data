#include <bits/stdc++.h>
using namespace std;
int n;
long long x1,x2,sum,maxx;
struct node{
	long long m;
	char c;
}a[200010];
string s;
bool flag=0,f=0;
int b[30];
char maxn;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		sum+=a[i].m;
		if(a[i].m>maxx){
			maxx=a[i].m;
			maxn=a[i].c;
		}
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=a[i].m;i++){
			s+=a[i].c;
		}
	}
	for(int i=1;i<=sum-1;i++){
		if(a[i].c!=a[i+1].c){
			f=1;
		}
		b[a[i].c-'a'+1]++;
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	if(s.size()==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			flag=1;
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=26;i++){
		if(b[i]!=0) cnt++;
	}
	for(int i=1;i<=n;i++){
		if(a[i].c==maxn){
			x1+=a[i].m;
		}else{
			x2+=a[i].m;
		}
	}
	cout<<min(x1,x2);
	return 0;
}
