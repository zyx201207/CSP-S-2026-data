#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+10;
int n,m;
pair<string,int> get2(int x){
	string s;
	int ln=0,p1=0;
	while(x>0){
		if(x%2==0) s='0'+s;
		else s='1'+s,p1++;
		x/=2;
		ln++;
	}
	s=string(abs(n-ln),'0')+s;
	return make_pair(s,p1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20){
		int a[25]={0};
		int mx=0,cnt=2147483647;string sp;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<1<<n;i++){
			cnt=2147483647;
			auto p=get2(i);
			string qz=p.first;
			int yi=p.second;
			if(yi!=m) continue;
			for(int i=0;i<n;i++){
				if(qz[i]=='1') cnt&=a[i+1];
			}
			if(cnt>=mx){
				mx=cnt;
				sp=qz;
			}
		}
		cout<<mx;
	}
	else cout<<0;
	return 0;
}
