#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	int len;
	char c;
}q[200009];
int s[200009];
inline int check(int l,int r,char a){//检测从l到r中有几个不是a的c字符
	int nowdis=0;
	for(int i=1;i<=n;i++){
		if(s[i]<=l){
			nowdis=i;
		}
	}
	int last=l,ans=0;
	for(int i=nowdis+1;i<=n;i++){
		if(q[i].c!=a){
			ans+=s[i]-last+1;
			//cout<<last<<" "<<s[i]<<endl;
			last=s[i];
		}
		if(s[i]>r || last>=r){
			//cout<<l<<" "<<r<<" "<<ans<<endl;
			return ans;
		}
	}
	return 0;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].len>>q[i].c;
		s[i]=s[i-1]+q[i].len;
	}
	
	int ans=0;
	for(int i=1;i<=n && s[i]<=(s[n]/2);i++){
		int l=min(s[n]-(s[i-1]+1)+1,s[n]-(s[i])+1);
		int r=max(s[n]-(s[i-1]+1)+1,s[n]-(s[i])+1);
		ans+=check(l,r,q[i].c);
	}
	cout<<ans;
	return 0;
}

