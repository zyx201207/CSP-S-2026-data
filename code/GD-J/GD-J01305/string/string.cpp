#include<bits/stdc++.h>
using namespace std;
long long n,m[200010],ans;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>m[i]>>c[i];
	for(int i=0,j=n-1;i<j;){
		if(c[i]!=c[j]){
			if(m[i]<m[j]) ans+=m[i],m[j]-=m[i],i++;
			else if(m[j]<m[i]) ans+=m[j],m[i]-=m[j],j--;
			else ans+=m[i],i++,j--;
		}
		else{
			if(m[i]<m[j]) m[j]-=m[i],i++;
			else if(m[j]<m[i]) m[i]-=m[j],j--;
			else i++,j--;
		}
	}
	cout<<ans;
	return 0;
} 
