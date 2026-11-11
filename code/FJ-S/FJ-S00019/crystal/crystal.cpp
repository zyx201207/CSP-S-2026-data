#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long n,m,a[N],ans,tmp=-1,cnt=0;
map<long long,long long> mp;
vector<long long> g;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(mp[a[i]]==0){
			cnt++;
			g.push_back(1);
			mp[a[i]]==cnt;
		}
		else g[mp[a[i]]]++;
	}
	long long tmp=m;
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		if(i<ans)break;
		m=tmp;
		long long tot=g[mp[a[i]]];
		int l=1;
		while(i-l>=1&&m>0){
			long long cha=a[i]-a[i-l];
			if(m-g[mp[a[i-l]]]*cha>=0){
				m-=g[mp[a[i-l]]]*cha;
				tot+=g[mp[a[i-l]]];
			}
			else{
				int s=m/cha;
				tot+=s;
				m-=s*cha;
			}
			l++;
			if(m<=0||m-(a[i]-a[i-l])<0||i-l<=0){
				break;
			}
		}
		ans=max(ans,tot);
	}
	cout<<ans;
	return 0;
}

