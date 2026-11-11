/**/
#include<bits/stdc++.h>
using namespace std;
int n,a,ans=0,cnt=0;
char s[2000000005],c;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			ans+=1;
			s[ans]=c;
		}
	}
	for(int i=1;i<=ans/2;i++){
		if(s[i]!=s[ans-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
