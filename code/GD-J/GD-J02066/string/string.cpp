#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long lent=0,ans=0,tmp=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		lent+=a[i];
	}
	lent/=2;
	char st[maxn];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			tmp++;
			st[tmp]=c[i];
			
		}
	}
	for(int i=1;i<=lent;i++){
		if(st[i]!=st[tmp+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
