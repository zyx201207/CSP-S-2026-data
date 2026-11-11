#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,x,f,q,b[200005],cnt;
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=a[i];
		
		for(int j=1;j<=30;j++){
			s[i]+=char(x%2+48);
			x/=2;
		}
	}
	for(int i=29;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='1'&&b[j]==0){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=pow(2,i);
			for(int j=1;j<=n;j++){
				if(s[j][i]=='0'){
					b[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}