#include<bits/stdc++.h>
using namespace std;
int n,m,x,f[200005],l,p[200005],ans=-1;
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=30;i++)p[i]=p[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>x;
		while(x){
			int a=x%2;
			s[i]=char(a+'0')+s[i];
			x/=2;
		}
		int qwq=s[i].size();
		l=max(l,qwq);
	}
	for(int i=1;i<=n;i++){
		int qwq=s[i].size();
		for(int j=1;j<=l-qwq;j++)s[i]='0'+s[i];
		//cout<<s[i]<<endl;
	}
	for(int len=0;len<l;len++){
		int cnt=0;
		if(ans==-1){
			for(int i=1;i<=n;i++)if(s[i][len]=='1')cnt++;
			if(cnt>=m){
				ans=p[l-len-1];
				for(int i=1;i<=n;i++){
					if(s[i][len]=='0')f[i]=1;
				}
			}
		}else{
			for(int i=1;i<=n;i++)if(!f[i]&&s[i][len]=='1')cnt++;
			if(cnt>=m){
				ans+=p[l-len-1];
				for(int i=1;i<=n;i++){
					if(s[i][len]=='0')f[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

