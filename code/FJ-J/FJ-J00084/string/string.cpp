#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],sum,cnt,f,ans,j;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch;
		b[i]=ch-'a';
	}
	j=n;
	for(int i=1;i<=n;i++){
		while(j>i&&a[j]<=a[i]){
			if(b[i]!=b[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		if(j==i) break;
		if(a[i]){
			a[j]-=a[i];
			if(b[i]!=b[j]) ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}
//I love yangyang and feixue
