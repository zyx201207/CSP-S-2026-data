#include<bits/stdc++.h>
using namespace std;
int n,a[200005],c[200005],h1,h2;
long long cnt;
char m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	h2=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>m;
		c[i]=m-'a'+1;
	}
	while(h1<h2){
		int d=min(a[h1],a[h2]);
		if(c[h1]!=c[h2]){
			cnt+=d;
		}
		a[h1]-=d;
		a[h2]-=d;
		if(a[h1]==0){
			h1++;
		}
		if(a[h2]==0){
			h2--;
		}
	}
	cout<<cnt;
	return 0;
}
