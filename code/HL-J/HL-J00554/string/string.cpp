#include<bits/stdc++.h>
using namespace std;
int n,a[200010],ans=0,l=0;
char b[200010],s[200000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
	}
	int k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[k]=b[j];
			k++;
		}
	}
	s[l]=b[n];
	int m=l;
	l/=2;
	for(int i=1;i<=l;i++){
		if(s[i]!=s[m-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
