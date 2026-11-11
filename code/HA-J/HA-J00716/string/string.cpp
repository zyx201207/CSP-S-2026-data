#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,len;
char a[N],c;
long long cnt[N],x,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		if(a[len]==c) cnt[len]+=x;
		else a[++len]=c,cnt[len]=x; 
	}
	//for(int i=1;i<=len;i++) cout<<cnt[i]<<" ";
	if(len==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=ceil(len/2);i++){
		int pos=len-i+1;
		if(a[i]==a[pos]){
			if(cnt[i]==cnt[pos]) continue;
			else{
				if(cnt[i]<cnt[pos]){
					if(cnt[i+1]+cnt[i]>=cnt[pos]){//1
						cnt[i+1]-=(cnt[pos]-cnt[i]);
					}
				}else{
					if(cnt[i]<=cnt[pos]+cnt[pos-1]){//1
						cnt[pos-1]-=(cnt[i]-cnt[pos]);
					}
				}
				ans+=max(cnt[i],cnt[pos]);
				//cout<<i<<":"<<ans<<" cnt:"<<cnt[i]<<"/"<<cnt[pos]<<"\n";
			}
		}else{
			if(cnt[i]==cnt[pos]) ans+=cnt[i];
			else{
				if(cnt[i]<cnt[pos]){
					if(cnt[i+1]+cnt[i]>=cnt[pos]){//1
						cnt[i+1]-=(cnt[pos]-cnt[i]);
					}
				}else{
					if(cnt[i]<=cnt[pos]+cnt[pos-1]){//1
						cnt[pos-1]-=(cnt[i]-cnt[pos]);
					}
				}
				ans+=max(cnt[i],cnt[pos]);
				//cout<<i<<":"<<ans<<" cnt:"<<cnt[i]<<"/"<<cnt[pos]<<"\n";
			}
		}
	}
	cout<<ans;
	return 0;
}

