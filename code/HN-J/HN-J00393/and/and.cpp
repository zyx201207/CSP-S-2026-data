#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
string b[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=LLONG_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		int s=0,c[200];
		int w=a[i];
		while(w>0){
			s++;
			char g=w%2+'0';
			b[i]+=g;
			w/=2;
		}
	}
	if(m==1){
		cout<<maxx;
	}else if(m==n){
		string f=b[1];
		for(int i=2;i<=n;i++){
			for(int j=0;j<min(f.size(),b[i].size());j++){
				if(f[j]=='1'&&b[i][j]=='1'){
					f[j]='1';
				}else if(f[j]!='2'){
					f[j]='0';
				}
			}
			for(int j=min(f.size(),b[i].size());j<max(f.size(),b[i].size());j++){
				f[j]='2';
			}
		}
		int q=0,o=-1;
		for(int i=0;i<f.size();i++){
			if(f[i]!='2'){
				o++;
				q+=(f[i]-'0')*(1<<o);
			}
		}
		cout<<q;
	}else if(m==2){
		int maxxx=LLONG_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				string f=b[i];
				for(int k=0;k<min(f.size(),b[j].size());k++){
					if(f[k]=='1'&&b[j][k]=='1'){
						f[k]='1';
					}else{
						f[k]='0';
					}
				}
				for(int k=min(f.size(),b[j].size());k<f.size();k++){
					f[k]=2;
				}
				int q=0,o=-1;
				for(int k=0;k<f.size();k++){
					if(f[k]!='2'){
						o++;
						q+=(f[k]-'0')*(1<<o);
					}
				}
				maxxx=max(maxxx,q);
			}
		}
		cout<<maxxx;
	}else{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0; 
}//4 2 3 15 12 12
