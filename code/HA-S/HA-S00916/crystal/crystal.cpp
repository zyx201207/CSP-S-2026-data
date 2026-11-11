#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') f=(ch=='-')?(-1):f,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=1;
long long  du[500005];
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[m+1]; 
	for (int i=0;i<n;i++){
		cin>>du[i];
	}
	sort(du,du+500005);
	if(n<=m)for(int i=0;i<n;i++) a[i]=du[i];
	else{
		for(int i=0;i<m;i++) a[i]=du[i];
	}
	
	long long dengcha=a[2]-a[1];
	long long  chance=m;
	long long  ans=0;
	if(dengcha>chance){
		int ans=0;
	}
	else{
		int i=1;
		while (chance-=dengcha*i>0){
		ans++;
		i++;
		if(ans>=m) int i=1;
	}
	if(ans<m) ans++;
	}
	if(dengcha==0) cout<<m;
	else cout<<ans;
	return 0;}


