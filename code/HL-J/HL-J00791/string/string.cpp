#include<bits/stdc++.h>
using namespace std;
char b[1000000];
long long a[1000000];
int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
long long n,d,s=0,v,ans=0,aaa=0,p,q;

cin>>n;
for(long long i=1;i<=n;i++){
	cin>>a[i]>>b[i];
	d+=a[i];
}

d=d/2+1;
for(long long i=1;i<=n;i++){
    s+=a[i];
	if(s>d){
		v=i;
	}	
}
for(long long i=1;i<n;i++){
	if(b[i]==b[i+1]){
		aaa++;
	}
}
if(aaa==n-1){
	cout<<0;return 0;
}
int h=n;
for(int i=1;i<v;i++){e:;
	if(h<=i){
		cout<<ans;return 0;
	}
	if(b[i]==b[h]&&a[i]>a[h]){
		a[i]-=a[h];h--;goto e;
	}
	else if(b[i]==b[h]&&a[i]>a[h]){
		a[h]-=a[i];continue;
	}
	else if(b[i]==b[h]&&a[i]==a[h]){
		h--;continue;
	}
	else if(b[i]!=b[h]&&a[i]>a[h]){
		ans+=a[h];h--;goto e;
	}
	else if(b[i]!=b[h]&&a[i]<a[h]){
		ans+=a[i];a[h]-=a[i];
	}
	else if(b[i]!=b[h]&&a[i]==a[h]){
		ans+=a[h];h--;
	}
}

	return 0;
}