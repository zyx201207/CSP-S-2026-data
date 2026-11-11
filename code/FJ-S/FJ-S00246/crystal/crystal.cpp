#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],ans=-1e9;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int now=0,ch=0,len=1,temp=m,l=1;
	for(register int i=1;i<n;i++){
		if(a[i]==a[i+1]){len++;continue;}
		ch=a[i+1]-a[i];
		//cout<<len<<" "<<ch<<" "<<temp<<" "<<i<<"\n";
		ans=max(ans,len);
		while(ch*len>temp&&l<i){
			temp+=(a[i]-a[l]);
			l++;
			len--;
		}
		//cout<<len<<" "<<ch<<" "<<temp<<" "<<i<<"\n------------\n";
		if(ch*len>temp){
			now=0;
			continue;
		}else{
			now=ch*len;
			temp-=now;
			len++;
		}
	}
	ans=max(ans,len);
	cout<<ans;
	return 0;
} 
