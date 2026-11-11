#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
string s;
int a[N];
char b[N];
void pd(int x,int a){
	for(int i=1;i<=x;i++){
		s+=a;
	}
	cout<<s;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		pd(a[i],b[i]);
	}
	int len=s.size();
	int cnt=0;
	if(len%2==0){
		for(int i=0,j=len-1;i<=len/2,j>i;i++,j--){
			if(s[i]!=s[j])cnt++;
		}
	}else{
		for(int i=0,j=len-1;i<=len/2,j>=i;i++,j--){
			if(s[i]!=s[j])cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
