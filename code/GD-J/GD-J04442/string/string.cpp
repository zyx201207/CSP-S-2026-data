#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,cnt,pre=1;
int a[maxn],c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		char cq;
		cin>>a[i]>>cq;
		c[i]=cq-'a';
	}
	for(int i=n;i>=1; ){
		for(int j=pre;j<i; ){
			if(c[i]!=c[j]) cnt++;
			a[i]-=1,a[j]-=1;
			if(!a[j]){
				pre=j+1;
				j++;
			}
			if(!a[i]) i--;
		}
		if(pre==i) break;
	}
	cout<<cnt;
	return 0;
}
