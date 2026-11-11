#include<bits/stdc++.h>
using namespace std;
long long n,m,x[200005],k,a[200005][35],maxx=-1,b[35];
string s;
bool book[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		maxx=max(maxx,(long long)ceil(log2(x[i])));
	}
	for(int i=1;i<=n;i++){
		string st="";
		while(x[i]>0){
			st=char(x[i]%2+48)+st,x[i]/=2;
		}
		if(st.size()<maxx){
			int len=st.size();
			for(int j=1;j<=maxx-len;j++)
				st='0'+st;
		}
		for(int j=0;j<maxx;j++)a[i][j+1]=st[j]-48;
	}
	for(int i=1;i<=maxx;i++){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(!book[j])cnt+=a[j][i];
		if(cnt<m){
			s+='0';
			continue;
		}
		s+='1';
		for(int j=1;j<=n;j++){
			if(book[j])continue;
			if(a[j][i]==0)book[j]=true;
		}
	}
	int kk=1,res=0;
	for(int i=maxx-1;i>=0;i--)
		res+=int(s[i]-48)*kk,kk*=2;
	//cout<<s;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=maxx;j++)cout<<a[i][j];
		cout<<'\n';
	}*/
	cout<<res;
	return 0;
}
/*
31:11111
 3:00011
 1:00001
15:01111
 7:00111
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
