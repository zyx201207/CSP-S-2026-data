#include<bits/stdc++.h>
using namespace std;
long long n,m,len=1,ans=0;
char a[2000000005],s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>s;
		for(int j=len;j<len+m;j++){
			a[j]=s;
		}
		len+=m;
	}
	len-=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[len]){
			ans++;
		}
		len--;
	}
	cout<<ans;
	return 0;
}
