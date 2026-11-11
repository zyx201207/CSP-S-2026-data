#include<bits/stdc++.h>
using namespace std;
long long c[10005],a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		string s="";
		for(long long j=i;j<=n;j++){
			char hh=a[j]+'#';
			if(s.find(hh)>n){
				s=s+hh;
			}else{
				s.erase(s.find(hh),s.size()-s.find(hh));
				s=s+hh;
			}
		}
		for(long long j=0;j<s.size();j++){
			c[s[j]-'#']++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
