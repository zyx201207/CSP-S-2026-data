#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005],b[300005],d;
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		s='0';
		for(long long j=i;j<=n;j++){
			b[a[j]]++;
		    if(b[a[j]]==1)s+=a[j]+'0';
		    else {
		    	s='0';	
				memset(b,0,sizeof(b));
		    	s+=a[j]+'0';
			}
		}
		if(s.size()!=0){
			for(long long k=0;k<=s.size();k++){
				ans[s[k]-'0']++;
			}
		} 
	} 
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
