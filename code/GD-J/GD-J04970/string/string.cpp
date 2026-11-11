#include <bits/stdc++.h>
using namespace std;
long long n,a,k,l,r,cnt,ans;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a);
		cin>>s;	
		while(a!=0){
			s1[k++]=s[0];
			a--;
		}
	}
	l=0,r=k-1;
	while(r!=-1){
		s2[l++]=s1[r--];
	}
	for(long long i=0;i<k;i++) if(s1[i]==s2[i]) cnt++;
	if(cnt==k){
		cout<<"0";
		return 0;
	}else{
		for(long long i=0;i<k;i++){
			if(s2[i]!=s1[i]) ans++;
		}
		cout<<ans/2;
	}	
	return 0;
}
