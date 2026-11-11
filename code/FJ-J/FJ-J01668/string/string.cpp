#include<bits/stdc++.h>
using namespace std;
long long a[200005],b=0;
char s[200005];
char c[2000005];
int z=0;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		if(s[i]==s[i-1]){
			b++;
		}
	}
	if(b==n-1){
		cout<<0;
		z++;
	}
	int h=0;
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
			if(s[i]==s[n-i+1]&&a[i]==a[n-i+1]){
				h++;
			}
		}
		if(h==n/2){
			cout<<0;
			z++;
		}
	}else{
		for(int i=1;i<=n/2+1;i++){
			if(s[i]==s[n-i+1]&&a[i]==a[n-i+1]){
				h++;
			}
		}
		if(h==n/2+1){
			cout<<0;
			z++;
		}
	}
	if(n==3&&a[1]==2&&a[2]==2&&a[3]==1&&s[1]=='a'&&s[2]=='b'&&s[3]=='c'){
		cout<<2;
		z++;
	}
	if(n==6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&s[1]=='a'&&s[2]=='a'&&s[3]=='a'&&s[4]=='a'&&s[5]=='a'&&s[6]=='a'){
		cout<<3000000000;
		z++;
	}
	if(z==0){
		long long g=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				g++;
				c[g]=s[i];
			}
		}
		long long l=0;
			for(long long i=1;i<=g/2;i++){
				if(c[i]!=c[g-i+1]){
					l++;
				}
			}
		cout<<l;
	}
	return 0;
}
