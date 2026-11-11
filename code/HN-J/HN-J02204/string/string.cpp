#include<bits/stdc++.h>
using namespace std;
string s[2000005];
int n,i,j;
long long a[2000005],ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(i=1;i<=n/2;i++){
		if(s[i]!=s[n-i+1]){
			if(a[i]==a[n-i+1]){
				ch=ch+a[i];
			}else if(a[i]!=a[n-i+1]){
				ch=ch+(max(a[i],a[n-i+1])-min(a[i],a[n-i+1]));
			}
		}else if(a[i]!=a[n-i+1]){
			bool f=true;
			for(j=1;j<=n;j++){
				if(a[j]!=a[i]){
					f=false;
					break;
				}
			}
			if(f==false){
				ch=ch+(max(a[i],a[n-i+1])-min(a[i],a[n-i+1]));
			}
		}
	}
	cout<<ch;
	return 0;
}
