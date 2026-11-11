#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100000005],cnt=1,panduan=0,ans=0,l=0;
	char c[100000005];
	string s[10005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			s[ans++]=c[i];
		}
	}
	for(int i=1;i<=n;i++){
		l+=a[i];
	}
	for(int i=0;i<=l;i++){
		for(int j=1;j<=l;j++){
			if(s[j]!=s[l+1-j]){
				panduan=1;
				break;
			}
		}
		if(panduan==0){
			cout<<i;
			break;
		}
		s[i]=s[l+1-(i+1)];
		
		
	}
	return 0;
}
