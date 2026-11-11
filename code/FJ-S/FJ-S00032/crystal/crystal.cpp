#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n;
long long m;
long long a[N],f[N],c[N][N];
int mx=-1;
long long read(){
	long long x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int x=0;
		for(int k=1;k<=i;k++){
			for(int j=k;j<=i;j++){
				c[i][k]+=a[i]-a[j];
			}
		}

	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<c[i][j]<<' ';
			if(c[i][j]==m){
				mx=max(mx,i);
			}
		}
		//cout<<endl;
	}
	cout<<mx;
	return 0;
} 
