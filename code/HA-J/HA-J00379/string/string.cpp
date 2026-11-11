#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,c=0,h,cnt=0,a[100000];
	bool p=1;
	cin>>n;
	string s[20000],s1[10000],s2[10000],b[10000];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]) p=0;
	}if(p){
		for(int i=0;i<n;i++){
			s[i]=b[i];
			c+=a[i];
			cnt++;
		}
	}else{
		for(int i=0;i<n;i++){
			while(a[i]--){
				s[cnt]=b[i];
				c+=a[i];
				cnt++;
			}
		}
	}cnt++;
	if(cnt%2==0) h=1;
	else h=0;
	for(int i=0;i<cnt/2-h;i++){
		s1[i]=s[i];
		s2[i]=s[cnt-i-2];
	}int ans=0;
	for(int i=0;i<cnt/2;i++){
		if(s1[i]!=s2[i]) ans++;
	}if(p) cout<<ans*a[0];
	else cout<<ans;
	return 0;
} 
