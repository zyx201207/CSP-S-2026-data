#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b=0,c=0,ma=-0x3f3f3f3f;
string e[200005],z[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int c=a[i];
		for(int j=1;c!=0;j++){
			b=a[i]%2;
			e[i]+=b;
			c/=2;
		}
		
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>ma){
				ma=a[i];
			}
		}
		cout<<ma;
	}
	if(m==n){
		string s = e[1],x=s;
		int cnt =1,z=0,cf;
		for(int i=2;i<=n;i++){
			for(int j=min(e[i].size(),s.size());j>=1;j--){
				if(e[i][j]==s[j]){
					x[cnt++]='1';
				}
				
			}
		}
		cf=x.size()-1;
		for(int i=1;i<=n;i++){
			if(x[i]=='1'){
				for(int j=1;j<=cf;j++){
					z+=2;
				}
			}
			cf-=1;
		}
		cout<<z;
	}
	
	
	return 0;
}
