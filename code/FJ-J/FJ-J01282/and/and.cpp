#include <bits/stdc++.h>
#define int long long
#define fs(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
int arr[1000007];
void Bol(){
	int n,m;
	scanf("%lld%lld",&n,&m);
	if(n==1){
		int a;
		cin>>a;
		printf("&lld",a);
		return ;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>=mx) mx=arr[i];
	}
	if(m==1){
		printf("&lld",mx);
		return ;
	}
	mx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((arr[i]&arr[j])>mx) mx=arr[i]&arr[j];
		}
	}
	if(m==2){
		printf("&lld",mx);
		return ;
	}
	int mm=arr[1];
	for(int i=2;i<=n;i++){
		mm&=arr[i];
	}
	if(m==n){
		printf("&lld",mm);
		return ;
	}
	mx=arr[2];
	for(int i=3;i<=n;i++){
		mx&=arr[i];
	}
	mm=arr[1];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j) continue;
			mm&=arr[j];
		}
		if(mm>=mx) mx=mm;
	}
	printf("&lld",mx);
}
int T;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	T=1;
	while(T--){
		Bol();
	}
	return 0;
}
