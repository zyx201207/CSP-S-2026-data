#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long n,m,in[maxn],ll[maxn],ans;
string a[maxn];
bool chosen[maxn];
set<long long>q;
string che(long long r){
	string ba="",re="";int cnt=0;
	do{
		cnt++;
		ba+=char(r%2+'0');
		r=r/2;
	}while(r!=0);
	for(int i=1;i<=30-cnt;i++)re+='0';
	for(int i=cnt-1;i>=0;i--)re+=ba[i];
	return re;
}
int le(string r){
	int u=0;
	for(int i=0;i<r.length();i++)u++;
	return u;
}
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	/*
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>in[i];
		a[i]=che(in[i]);
		int cnt=0,c=in[i];
		while(c){
			cnt++;
			c=c/2;
		}
		le[i]=cnt;
	}
	for(int cn=0;cn<30;cn++){
		int mx=0,nx=0;
		for(int i=1;i<=n;i++){
			if(a[i][cn]=='1'){
				if(le[i]>le[mx]){
					nx=mx;
					mx=i;
				}else if(le[i]>le[nx])nx=i;
			}
		}
		if(mx==0||nx==0)continue;
		else {
			m-=2;
			
		}
	}
	*/
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>in[i];
	}
	sort(in,in+n+1);
	ans=in[n];
	for(int i=n,j=1;j<=m;i--,j++){
		ans=(ans&in[i]);
	}
	cout<<ans;
	return 0;
} 
