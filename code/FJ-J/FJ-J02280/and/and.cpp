#include<bits/stdc++.h>
using namespace std;
unsigned int st[31][2];
int a[200003];int n,m;
void init(){
	int j,c;
	for(int i=0;i<n;i++){
		c=a[i];
		for( j=31;c!=0&&j>=0;j--){
		if(st[j][0]>c) continue;
		c-=st[j][0];st[j][1]++;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	st[0][0]=1;
	for(int i=1;i<32;i++)
	st[i][0]=st[i-1][0]*2;
	unsigned int ans=0,kl,maxn=0,fk=0xffffffff;
	bool fl=true;
	cin>>n>>m;
	kl=m;
	for(int i=0;i<n;i++){
		cin>>a[i];if(maxn<a[i]) maxn=a[i];
		fk&=a[i];fl&=(a[i]==i);
	}
	if(fl){
		for(int j=31;j>=0;j--) fl|=(n==st[j][0]);
		if(fl){cout<<n-m;return 0;}
	}
	
	if(m==1){
		cout<<maxn;return 0;
	}
	if(m==n){
		cout<<fk;return 0;
	}
	init();
	for(int j=31;kl!=0&&j>=0;j--){
		if(st[j][1]<m) continue;
		ans+=st[j][0];kl--;
	}
	cout<<ans;
	return 0;
}
