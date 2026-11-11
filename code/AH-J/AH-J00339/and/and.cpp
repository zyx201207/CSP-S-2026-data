#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//cout<<1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long mx=-0x3f3f3f3f;
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}else if(m==n){
		mx=a[1];
		for(int i=2;i<=n;i++){
			mx&=a[i];
		}
		cout<<mx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
