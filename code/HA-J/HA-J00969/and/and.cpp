#include<bits/stdc++.h>
using namespace std;
long long a[20000000],c[20000000];
string b[101010101];
int an,p;
string s;
string erg(int n){
	int k=n;
	string s1;
	while(k){
		char c=k%2+'0';
		s1=c+s1;
		k/=2;
	}
	return s1;
}
int yi(int n){
//	cout<<n<<" ";
	//cout<<b[n]<<endl;
	int cnt=0;
	for(int i=0;i<b[n].size();i++){
		if(s[i]=='1'&&b[n][i]=='1'){
			cnt++;
		}
	}
	//cout<<cnt<<endl;
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(an<a[i]){
			p=i;
			an=a[i];
		}
	}
	 s=erg(an);
	for(long long i=1;i<=n;i++){
		b[i]=erg(a[i]);
		c[i]=yi(i);
	}
	long long mx=-1,v,d;
	for(long long i=1;i<=m;i++){
		mx=-1,v=-1;
		for(long long i=1;i<=n;i++){
			if(mx<=c[i]&&a[i]>v){
				mx=c[i];
				v=a[i];
				d=i;
			}
		}
		c[d]=-1;
		an=an & v;
	}
	cout<<an;
}
