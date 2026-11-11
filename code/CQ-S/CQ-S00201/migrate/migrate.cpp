#include <bits/stdc++.h>
using namespace std;
int c,t,n,ans,sum;
long long int x[2000010],gc,d;
bool dcxl;
vector<int> v;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0' and ch<='9')){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
long long int read1(){
	long long int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0' and ch<='9')){
		if(ch=='-') f=-1;
		ch=getchar(); 
	}
	while(ch>='0' and ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void dfs(int l,int r,int c){
	if(l==r){
		v[c]++;
		return;
	}
	int xz=l+1;
	while(abs(x[xz]-x[l])<=d and xz<=r){
		dfs(xz,r,c+1);
		xz++;
	}
	return;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ans=0;
		n=read(),d=read1();
		v.resize(n+1);
		dcxl=1;
		for(int i=1;i<=n;i++){
			x[i]=read1();
			if(i>2) if(abs(x[i-2]-x[i-1])!=abs(x[i-1]-x[i])) dcxl=0;
		} 
		if(dcxl){
			gc=abs(x[1]-x[2]);
			d=(d/gc);
			sum=3; 
			if(d<=1) ans=0;
			else{
				for(int i=2;i<d;i++) sum+=2; 
				for(int i=1;i<=n;i++) if((i+sum)<=n) ans++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					sum=0;
					dfs(i,j,0);
					bool j1=1;
					for(int k=1;k<=n;k++){
						if(v[k]!=0 and j1){
							j1=0;
							if(v[k]==2) ans++;
						}
						v[k]=0;
					}
				}
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
}
//1 4 7 10 13 16 19 22
//7
