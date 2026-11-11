#include<bits/stdc++.h>
using namespace std;
long long n,k,l[200005],r[200005],ans=0,cnt;char x;char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long now=1;
	for(int i=1;i<=n;i++){
		cin>>k>>x;
		l[i]=now;
		r[i]=now+k-1;
		s[i]=x;
		now+=k;
	}
	cnt=now-1;
	long long ll;
	long long nj=0,o=1;
	bool p=1;
	for(int i=n;i>=1;i--){
		ll=1+cnt-l[i];
		if(ll>=cnt/2+cnt%2){
			ll=cnt/2+cnt%2;
			p=0;
		}
		while(ll>=r[o]){
			if(s[o]!=s[i]){
				ans+=r[o]-nj;
			}
			nj=r[o];
			o++;
		}
		if(s[o]!=s[i]){
			ans+=ll-nj;
		}
		nj=ll;
		if(p==0){
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
