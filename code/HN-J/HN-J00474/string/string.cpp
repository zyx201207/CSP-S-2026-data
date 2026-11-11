#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n;
int a[200000+10];
char b[100000+100000+10]={};
int c[200000+10];
char d[200000+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}for(int i=1;i<=n;i++){
		c[i]=a[n-i+1];
		d[i]=b[n-i+1];
	}
	int l1,l2;
	l1=l2=1;
	while(1){
		int mn=min(a[l1],c[l2]);
		if(b[l1]!=d[l2]){
			ans+=mn;
		}a[l1]-=mn;
		c[l2]-=mn;
		if(a[l1]==0){
			l1++;
		}if(c[l2]==0){
			l2++;
		}if(l1==n+1&&l2==n+1&&a[l1]==0&&c[l2]==0){
			break;
		}
	}cout<<ans/2;
	return 0;
}
