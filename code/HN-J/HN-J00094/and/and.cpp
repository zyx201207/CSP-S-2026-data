#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct st{
	int a;
	string r;
}s[200005];
int n,m,flag[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		int cnt=s[i].a;
		string x="";
		while(cnt){
		    if(cnt%2==0)x="0"+x;
			else x="1"+x;
			cnt/=2;
		} 
		len=max(len,(long long)x.size());
		s[i].r=x;
	}
	for(int i=1;i<=n;i++){
		int len2=len-s[i].r.size();
	    if(s[i].r.size()<len)for(int j=1;j<=len2;j++){
	    	s[i].r='0'+s[i].r;
		}
    }
	int cnt,ans=0;
	for(int i=0;i<len;i++){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(flag[j])continue;
			if(s[j].r[i]=='1')cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(s[j].r[i]=='0')flag[j]=1;
			}
		}
    }
    for(int i=1;i<=n;i++){
		if(flag[i] or m==0)continue;
		m--;
		if(ans==0)ans=s[i].a;
		else ans=(ans&s[i].a);
	}
	cout<<ans;
}
