#include<bits/stdc++.h>
using namespace std;
int n;
long long h,jh;
string s;
struct nod{
	long long ai;
	char ci;
}a[200009];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	s+='0';
	for(int i=0;i<n;i++){
		cin>>a[i].ai>>a[i].ci;
		h+=a[i].ai;
		long long aa=a[i].ai;
		while(aa--) s+=a[i].ci;
	}
	if(h%2==0){
		long long hh=h/2;
		for(long long i=1;i<=hh;i++){
			if(s[i]!=s[s.size()-i]){
				jh++;
				cout<<s[i]<<'\n';
			}
		}
	}
	else{
		long long hh=h/2+1;
		for(long long i=1;i<hh;i++){
			if(s[i]!=s[s.size()-i+1]) jh++;
		}
	}
	cout<<jh;
	return 0;
}
