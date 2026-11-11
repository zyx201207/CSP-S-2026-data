#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,a[200005],ft=-1,cnt=0;
struct Two{
	string s;
	bool t=0;
}v[200005];
void to_two(int n){
	string x="";
	while(n){
		x+=(n%2)+'0',n/=2;
	}
	for(int i=x.size();i<=30;i++)x+='0';
	reverse(x.begin(),x.end());
	v[++cnt].s=x;
	return;
}
int find_x(){
	bool l=1;
	for(int i=0;i<30;i++){
		vector<int> f;
		int all=0;
		for(int j=1;j<=n;j++){
			if((v[j].t||l)&&v[j].s[i]=='1'){
				all++;
				f.push_back(j);
			}
		}
		if(all<m)continue;
		if(all==m){
			int ans=a[f[0]];
			for(int i=1,sz=f.size();i<sz;i++){
				ans&=a[f[i]];
			}
			return ans;
		}
		if(all>m){
			l=0;
			for(int i=0,sz=f.size();i<sz;i++){
				v[f[i]].t=1;
			}
		}
		if(i==29){
			int ans=a[f[0]];
			for(int i=1,sz=f.size();i<sz&&i+1<n;i++){
				ans&=a[f[i]];
			}
			return ans;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ft=max(a[i],ft);
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans<<'\n';
		return 0;
	}else if(m==2){
		int all=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)all=max(all,a[i]&a[j]);
		}
		cout<<all<<'\n';
		return 0;
	}else if(m==1){
		cout<<ft<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		to_two(a[i]);
	}
	cout<<find_x()<<'\n';
	return 0;
}
