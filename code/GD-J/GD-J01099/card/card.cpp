#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long v[500005];
string s;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=1;i<=n;i++){
	s="";
	for(int j=i;j<=n;j++)
	{
		for(int x=0;x<s.size();x++){
			if(s[x]==char(a[j]+48)){
				s.erase(x,s.size()-x+1);
				break;
			}
		}
		s+=(a[j]+48);
	}
	for(int j=0;j<s.size();j++){
		v[s[j]-48]++;
	}
	 
}
for(int i=1;i<=m;i++){
	cout<<v[i]<<' ';
}
//1 2 3 
// 0 1 2
return 0;
}

