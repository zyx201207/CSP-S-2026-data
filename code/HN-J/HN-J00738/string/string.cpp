#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,len,l[200005],y[200005];
string s[20000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	k=1;
	int kk=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		len+=a;
		for(int j=1;j<=a;j++){
			kk++;
			s[k][kk]=c;
			if(kk>=15){
				k++;
				kk=0;
			}
		}
	}
	for(int i=1;i<=len;i++){
		if(i<=len/2){
			int x,y,x1,y1;
			if(i%15==0){
				x=i/15;
				y=15;
			}
			else{
				x=i/15+1;
				y=i%15;
			}
			if((len-i+1)%15==0){
				x1=(len-i+1)/15;
				y1=15;
			}
			else{
				x1=(len-i+1)/15+1;
				y1=(len-i+1)%15;
			}
			if(s[x][y]!=s[x1][y1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
