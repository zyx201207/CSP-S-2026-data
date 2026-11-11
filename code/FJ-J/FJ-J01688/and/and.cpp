#include<bits/stdc++.h>
using namespace std;
long long a,x[35],f[35],ans;
int ma;
string p[200005],r[200005];
bool pd(string x,string y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	x[0]=1;
	for(int i=1;i<=30;i++){
		x[i]=x[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		int k=0;
		for(int j=0;j<=30;j++){
			if(a&1){
				r[i]+='1';
				f[j]++;
				if(f[j]>=m)ma=max(ma,j);
			}
			else r[i]+='0';
			if(a)a>>=1;	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=ma;j++){
			p[i]+=r[i][j];
	    }
	}
	for(int i=1;i<=n;i++){
		reverse(p[i].begin(),p[i].end());
	}
	sort(p+1,p+n+1,pd);
	for(int i=0;i<=ma;i++){
		for(int j=1;j<=m;j++){
			if(p[j][i]=='0'){
				break;
			}
			if(j==m){
				ans+=x[ma-i];
			}
		}
	}
	cout<<ans;
	return 0; 
}
