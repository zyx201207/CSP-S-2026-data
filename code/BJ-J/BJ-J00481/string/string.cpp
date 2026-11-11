#include<bits/stdc++.h>
using namespace std;
struct node{
	int w;
	char s;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].s;
		cnt+=a[i].w;a[i].w=cnt;
	}
	int q1=1,q2=n,ans=0;
	for(int i=1;i<=cnt/2;i++){
		if(i>a[q1].w){q1++;}
		if((n-i+1)<a[q2-1].w){q2--;}
		if(a[q1].s!=a[q2].s){ans++;}
	}
	cout<<ans;
	return 0;
}
