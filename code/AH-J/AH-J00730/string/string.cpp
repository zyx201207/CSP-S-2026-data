#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
long long n,ans=0;
int a[MAXN];
char b[MAXN],c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	for(int k=1;k<=ans;k++){
		for(int i=1;i<=n;i++){
			while(a[i]--){
				c[k]=b[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
