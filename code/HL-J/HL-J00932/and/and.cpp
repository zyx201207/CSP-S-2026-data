#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,ans,z,a[200005],t[50],b[100]={1073741824,536870912,268435456,134217728,67108864,33554432,16777216,8388608,4194304,2097152,1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
string s[200005];
bool f[1000005];
bool cmp(string a,string b){
	return a>b;
}
int main (){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=0;j<=30;j++){
			if(x>=b[j]){
				s[i]+='1';
				x-=b[j];
				t[j]++;
			}else{
				s[i]+='0';
			}
		}
	}
	sort(s+1,s+n+1,cmp);

for(int i=0;i<=30;i++){
	int ct=0;
	for(int j=1;j<=n;j++){
		if(s[j][i]=='1'&&!f[j]){
			ct++;
		}
	}
	if(ct>=m){
	 ans+=b[i];
			for(int j=1;j<=n;j++){
		if(s[j][i]=='0'){
		f[j]=1;
		}
	}
	}
}
cout<<ans;
return 0;
}


