#include<bits/stdc++.h>
using namespace std;
long long n,b[200005],cnt,j,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>b[i]>>c[i];
	}
	ans=n;
	for(int i=1;i<=n/2;++i){
		if(c[i]!=c[ans-i+1]){
			cnt+=min(b[i],b[ans-i+1]);
			if(b[i]>b[ans-i+1]){
				b[i]-=b[ans-i+1];
				--i;
			}
			else if(b[i]<b[ans-i+1]){
				b[ans-i+1]-=b[i];
			}
		}
		else{
			if(b[i]>b[ans-i+1]){
				b[i]-=b[ans-i+1];
				--i;
			}
			else if(b[i]<b[ans-i+1]){
				b[ans-i+1]-=b[i];
			}
		}
	}
	cout<<cnt;
	return 0;
}
