#include<bits/stdc++.h>
using namespace std;
int n,a[1000000];
long long ans=1,cnt;
char c[1000000],s[1000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i==1){
			for(int j=1;j<=a[i];j++)
				s[j]=c[i];
			ans=a[i];
		}
		else{
			for(int j=ans+1;j<=ans+a[i];j++)
				s[j]=c[i];
			ans+=a[i];
		}
	}
	for(int i=1;i<=ans/2;i++){
		if(s[i]!=s[ans-i+1])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
