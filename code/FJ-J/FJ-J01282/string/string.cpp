#include <bits/stdc++.h>
#define int long long
#define fs(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
int arr[230];
void Bol(){
	int n;
	cin>>n;
	if(n==1){
		printf("0");
		return ;
	}
	int a;
	char c,z;
	cin>>a>>c;
	arr[c-'a']+=a;
	z=c;
	for(int i=2;i<=n;i++){
		cin>>a>>c;
		arr[c-'a']+=a;
		if(z!=c){
			z='1';
		}
	}
	if(z=='1'){
		printf("0");
		return ;
	}
	int mx=0;
	for(int i=0;i<=25;i++){
		if(arr[i]>mx) mx=arr[i];
	}
	printf("lld",mx);
}
int T;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	T=1;
	while(T--){
		Bol();
	}
	return 0;
}
