#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn=1;
ll a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ch=getchar();
	int flag=1;
	while((ch>='0'&&ch<='9')||ch=='-'){
		if(ch!='-') n=n*10+ch-'0';
		else flag=-1;
		ch=getchar();
	}n*=flag;
	flag=1;
	ch=getchar();
	while((ch>='0'&&ch<='9')||ch=='-'){
		if(ch!='-') m=m*10+ch-'0';
		else flag=-1;
		ch=getchar();
	}m*=flag;
	for(int i=1;i<=n;i++){
		ch=getchar();flag=1;
		while((ch>='0'&&ch<='9')||ch=='-'){
			if(ch!='-') a[i]=a[i]*10+ch-'0';
			else flag=-1;
			ch=getchar();
		}a[i]*=flag;
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n-maxn;i++){
		for(int j=i+maxn;j<=n;j++){
			if(s[j]-s[i-1]+m>=a[j]*(j-i+1)){
				if(maxn<j-i+1){
					maxn=j-i+1;
				}
			}
		}
	}cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
