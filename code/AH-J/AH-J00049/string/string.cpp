#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],s[200010],t,sum,_s[200010],l=1,r=1,ans;
char c[200010],ch[200010],_ch[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	c[n+1]='0';
	sum=a[1];
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1]){
			sum+=a[i+1];
		}
		else{
			s[++t]=sum;
			ch[t]=c[i];
			sum=a[i+1];
		}
	}
	for(int i=1;i<=t;i++){
		_s[i]=s[t-i+1];
		_ch[i]=ch[t-i+1];
	}
	while(l<=t&&r<=t){
		if(s[l]<_s[r]){
			if(ch[l]!=_ch[r]) ans+=s[l];
			_s[r]-=s[l];
			l++;
		}
		else if(s[l]==_s[r]){
			if(ch[l]!=_ch[r]) ans+=s[l];
			l++,r++;
		}
		else{
			if(ch[l]!=_ch[r]) ans+=_s[r];
			s[l]-=_s[r];
			r++;
		}
	}
	cout<<ans/2;
	return 0;
}
