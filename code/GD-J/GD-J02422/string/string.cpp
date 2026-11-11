#include<bits/stdc++.h>
using namespace std;
int n;
long long a[30]={},sum=0,cnt=0;
bool f[30]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		a[c-'a'+1]+=x;
		sum+=x;
		if(!f[c-'a'+1]){
			cnt++;
			f[c-'a'+1]=1;
		}
	}
	if(cnt==1)cout<<0;
	else if(sum%cnt==0)cout<<sum/cnt;
	else cout<<sum%cnt;
	return 0;
}
