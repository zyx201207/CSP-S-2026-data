#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[200005],ans=1,cnt,k;
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=32;i++) ans*=2;
	ans-=1; 
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(m==1){
		for(int i=1;i<=n;i++) cnt=max(cnt,ans&a[i]);
		cout<<cnt;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) cnt=max(a[i]&a[j],cnt);
			cout<<cnt;
		}
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			k=ans;
			for(int j=1;j<=n;j++){
				if(i!=j) k&=a[j];
			}
			cnt=max(cnt,k);
		}
		cout<<cnt;
	}
	else{
		for(int i=n;i>n-m;i--) ans&=a[i];
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
