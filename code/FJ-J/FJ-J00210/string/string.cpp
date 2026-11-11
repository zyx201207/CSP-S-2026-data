#include<bits/stdc++.h>
using namespace std;
struct node{
	int n;
	char c;
}a[200005];
long long t,h=0,ans=0;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i].n>>a[i].c;
		h+=a[i].n;
	} 
	long long l=1,r=t;
	while(l<r&&l<=t&&r>=1){
		if(a[l].n==0) l++;
		if(a[r].n==0) r--;
		if(a[l].c!=a[r].c){
			if(a[r].n<a[l].n) ans+=a[r].n,a[l].n-=a[r].n,a[r].n=0;
			else if(a[r].n>a[l].n) ans+=a[l].n,a[r].n-=a[l].n,a[l].n=0;
			else ans+=a[l].n,a[l].n=a[r].n=0;
		}else{
			if(a[r].n<a[l].n) a[l].n-=a[r].n,a[r].n=0;
			else if(a[r].n>a[l].n) a[r].n-=a[l].n,a[l].n=0;
			else a[l].n=a[r].n=0;
		}
//		cout<<l<<' '<<r<<"\n";
	}
	cout<<ans;
	return 0;//誓死效忠绝区0!!! 挽昼大人万岁!!!
}
