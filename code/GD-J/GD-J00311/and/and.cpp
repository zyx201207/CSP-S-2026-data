#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
int a[200005];
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int a1=a[i];
		cnt=0;
		while(a1){
			a1/=2;
			cnt++;
		}
		mx=max(mx,cnt);
	}
	mx--;
	for(int i=1;i<=n;i++){
		int a2=a[i];
		for(int j=mx;j>=0;j--){
			if(a2>=(1<<j)){
				s[i]+='1';
				a2-=(1<<j);
			}
			else{
				s[i]+='0'; 
			}
		}
	}
	int anst=0;
	bool bol[200005];
	memset(bol,true,sizeof(bol));
	for(int i=0;i<=mx;i++){
		cnt=0;
		vector<int>v;
		vector<int>qaq;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='1'&&bol[j]){
				cnt++;
				v.push_back(j);
			}
			if(s[j][i]=='0'&&bol[j]){
				qaq.push_back(j);
			}
		}
		if(cnt==m){
			int ans=2147483647;
			for(int j=0;j<m;j++){
				ans&=a[v[j]];
			}
			cout<<ans;
			return 0;
		}
		if(cnt>m){
			anst+=(1<<(mx-i));
			int len=qaq.size();
			for(int j=0;j<len;j++){
				bol[qaq[j]]=false;
			}
		}
	}
	cout<<anst;
	return 0;
} 
