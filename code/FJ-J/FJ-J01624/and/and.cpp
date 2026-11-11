#include<bits/stdc++.h>
using namespace std;//35
const long long N=1e6+67,M=5e3+67;
long long n,m,maxid,maxn;bool used[N];
string f,a[N];
string yu(string a,string b){
	if(a=="-")return b;
	if(b=="-")return a;
	for(long long i=0;i<a.size();i++){
		if(a[i]=='1'&&b[i]=='1'){
			a[i]='1';
		}
		else{
			a[i]='0';
		}
	}
	return a;
}
string da(string a,string b){
	for(long long i=0;i<a.size();i++){
		if(a[i]>b[i]){
			return a;
		}
		if(a[i]<b[i]){
			return b;
		}
	}
	return a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1,s;i<=n;i++){
		cin>>s;
		long long l=s;
		string z="";
		for(long long k=1;k<=30;k++){
			z+=l%2+'0';
			l/=2;
		}
		reverse(z.begin(),z.end());
		a[i]=z;
	}
	string f="-";
	while(m--){
		long long maxid=0;
		string o="-";
		for(long long i=1;i<=n;i++){
			if(!used[i]){
				string p=f;
				p=yu(p,a[i]);
				maxid= (da(p,o)==p)? i:maxid;
				o=da(p,o);
			}
			
		}
		f=o;
		used[maxid]=1;
	}
	reverse(f.begin(),f.end());
	long long point=1,ans=0;
	for(long long i=0;i<f.size();i++){
		if(f[i]=='1'){
			ans+=point;
		}
		point*=2;
	}
	cout<<ans;
	return 0;
}//4 2 3 15 12 12
