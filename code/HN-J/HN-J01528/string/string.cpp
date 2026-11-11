#include<bits/stdc++.h>
using namespace std;
long long n,a,m,ans,cnt,m2;
string b,g,s,g2;
bool spet;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			g+=b;
		}
	}
	m=g.size();
	int o=0;
	for(int i=m;i>=0;i--){
		g2[i]=g[o];
		o++;
		//cout<<g2[i];
	}
	for(int i=m;i>=0;i--){
		if(g2[i]!=g[i]){
			spet=1;
		}
	}
	if(spet==0){
		cout<<0;
		return 0;
	}
//	if(m%2==0){
		m=m/2;
//	}
//	else{
//		m=m/2+1;
//	}
	for(int i=m-1;i>=0;i--){
		s[ans]=g[i];
		//cout<<s[ans];
		ans++;
	}
	int d=m;
	for(int i=0;i<m;i++){
		d++;
		//cout<<s[i]<<'*'<<g[d]<<"%";
		if(s[i]!=g[d]){
			cnt++;
		}
		
	}
	cout<<cnt;
return 0;}
