#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,len,ans;
struct asdf{
	int sl;
	char zm;
}a[100000100];
string s,d;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sl>>a[i].zm;
		len+=a[i].sl;
		for(long long j=1;j<=a[i].sl;j++){
			s+=a[i].zm;
		}
	}
	for(int  i=len-1;i>=0;i--){
		d+=s[i];
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=d[i]) ans++;
	}
	cout<<ans;
	return 0;
}
//È¼¾¡ÁË
//¾¡Á¦ÁË 
