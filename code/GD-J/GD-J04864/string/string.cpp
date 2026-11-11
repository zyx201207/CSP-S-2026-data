#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+3;
string s;
char c[maxn];
long long ans=0,n,a[maxn];
long long L=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	//cout<<s<<endl;
	int l=0,r=s.length()-1;
	for(;l!=r && r-l!=1;){
		if(s[l]!=s[r]) ans++;
		//cout<<l<<" "<<r<<" ";
		//cout<<s[l]<<" "<<s[r]<<endl;
		l++;r--;
	}
	cout<<ans;
	return 0;
}
