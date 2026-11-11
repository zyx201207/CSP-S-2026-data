#include<bits/stdc++.h>
using namespace std;
long long cc,t,n,d,a[10],ans,len,cnt;
long long c[10];
void dfs1(long long pos,long long ed,long long siz){
	if(siz>=len)return;
	if(pos==ed){
		len=siz;
		return;
	}
	for(int i=pos+1;i<=ed;i++){
		if(a[i]-a[pos]>d)break;
		dfs1(i,ed,siz+1);
	}
}
bool check(){
	for(long long i=1;i<=len;i++)if(a[c[i]]-a[int(c[i-1])]>d)return false;
	return true;
}
void dfs2(long long pos,long long ed){
	if(pos==len+1){
		if(check())cnt++;
		return;
	}
	if(cnt>2)return;
	for(long long i=c[pos];i<=ed;i++){
		c[pos]=i;
		dfs2(pos+1,ed);
	}
}
int main(){
	cin>>cc>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",a[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
			len=n-1;
			dfs1(i,j,0);
            cnt=0;
            c[0]=i;
            dfs2(1,j);
            if(cnt==2)ans++;
			}
		}
	}	
	cout<<ans;
	
	return 0;
}
