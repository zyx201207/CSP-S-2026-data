#include<bits/stdc++.h>
using namespace std;
string s={0},b;
int len=0,n,a,ans=0;
void k1(int p,string q){
	while(p--) s+=q;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		cin>>b;
		k1(a,b);
		len+=a;
	}
	for(int i=1;i<=len/2;i++)
	if(s[i]!=s[len+1-i]) ans++;
	cout<<ans;
	return 0;
}


