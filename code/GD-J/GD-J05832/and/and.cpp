#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[100001];
string s[100001];
char c;
int b=INT_MIN;
int fug(string x,string y){
	string z;
	int z1[100001];
	int z2[100001];
	int num;
	for(int i=1;i<=max(x.size(),y.size());i++){
		for(int j=1;j<=max(x.size(),y.size());j++){
			z1[i]=x[i]-'0';
			z2[i]=y[i]-'0';
		}
		for(int j=1;j<=max(x.size(),y.size());j++){
			if(z1[i]==z2[i]&&z1[i]==1&&z2[i]==1){
				z=z+'1';
			}else{
				z=z+'0';
			}
		}
	}
	int t=1;
	for(int i=1;i<=z.size();i++){
		if(z[i]=='1'){
			num+=t;
		}
		t*=2;
	}
	return num;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]!=0){
			c=a[i]%2+'0';
			s[i]=c+s[i];
			a[i]/=2;
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<s[i]<<" ";
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int e=fug(s[i],s[j]);
			if(b<e){
				b=e;
			}
		}
	}
	cout<<b;
	return 0;
}
