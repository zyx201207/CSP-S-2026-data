#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char c[N],z[N],f[N],k[N];
long long n,a[N],num=0,cnt=0,sum=0,ans=0;
long long flag=0;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
			num+=a[i];
			for(int j=1;j<=a[i];j++){
				k[++cnt]=c[i];
			}
		}
		if(num%2==0){
		num/=2;
		for(int i=1;i<=num;i++){
			z[i]=k[i];
		}
		for(int i=n;i>num;i--){
			f[sum++]=k[i];
		}
	}else{
		num/=2;
		for(int i=1;i<=num;i++){
			z[i]=k[i];
		}
		for(int i=n;i>num+1;i--){
			f[++sum]=k[i];
		}
	}
	for(int i=1;i<=num;i++){
		if(z[i]!=f[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
