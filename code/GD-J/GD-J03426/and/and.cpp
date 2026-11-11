#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
string zhuan(int a){
	//cout<<endl<<"zhuan";
	string an="";
	if(a==0)return "0";
	while(a>1){
		if(a%2)an+='1';
		else an+='0';
		a%=2;
	}
	an+='1';
	return an;
}
long long annd(string a,string b){
	//cout<<endl<<"annd";
	long long anst=0;
	long long maxc=max(a.size(),b.size());
	for(int i=maxc-1;i>=0;i++){
		if(a[i]=='1'&&b[i]=='1'){
			anst+=pow(2,i);
			//cout<<anst<<endl;
		}
	}
	return anst;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=2;i<=m;i++){
		ans&=a[n-i];
	}
	cout<<ans;
	return 0;
}
