#include<bits/stdc++.h>
using namespace std;

int const M=2e5;
long long a[M];
char c[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	long long cnt=0,d=0;
	long long ch=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
		if(i!=1 and a[i]==a[i-1]) d++;
	}
	if(d==n-1){
		ch=a[1];
		for(int i=1;i<=n;i++){
			a[i]=1;
		}
		cnt=n;
	} 
	if(cnt<=10000){
		string s;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		for(int i=0;i<cnt/2;i++){
			if(s[i]!=s[cnt-i-1]){
				ans++;
			}
		}
		cout<<ans*ch;
	}
	return 0;
}
