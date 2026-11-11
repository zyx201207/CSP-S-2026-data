#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans,cnt;
string s;
struct node{
	int b,e,num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		a[i].b=cnt;
		cnt+=a[i].num;
		a[i].e=cnt-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++){
			s+=a[i].c;
		}
	}
	if(cnt%2==1){
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[cnt-1-i]) ans++;
		}
	}else{
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[cnt-1-i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}