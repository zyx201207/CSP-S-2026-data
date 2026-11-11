#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,len=0,cnt,ans=0;
string s;
char o[200010];
int f(int x,int y){
	for(int i=min(x,y);i>=2;i--){
		if(x%i==0&&y%i==0){
			return i;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s+='m';
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>o[i];
		if(i==1){
			cnt=a[i];
			continue;
		}
		else{
			if(a[i]%cnt==0){
				continue;
			}else{
				cnt=f(cnt,a[i]);
			}
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i]/cnt;
		for(int j=1;j<=a[i];j++){
			s=s+o[i];
		}
		len+=a[i];
	}
	if(len%2==0){
		long long q=0;
		for(int i=1;i<=len/2;i++){
			q=len/2-i;
			q=len/2+1+q;
			if(s[i]!=s[q]){
				ans++;
			}else{
				continue;
			}
		}
	}
	else{
		long long p=0;
		for(int i=1;i<=(len+1)/2;i++){
			p=(len+1)/2-i;
			p=(len+1)/2+p;
			if(s[i]!=s[p]){
				ans++;
			}else{
				continue;
			}
		}	
	}
	ans=ans*cnt;
	cout<<ans;
	return 0;
}
