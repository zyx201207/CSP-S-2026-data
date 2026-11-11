#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
string bin(int x){
	string ans="";
	while(x!=0){
		ans+=(x%2)+'0';
		x/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
bool one(string s){
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			ans++;
		}
	}
	if(ans==m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long u=1<<n;
	int maxx=-2147483647;
	for(int i=1;i<u;i++){
		string s=bin(i);
		if(s.size()==1){
			s="000"+s;
		}else if(s.size()==2){
			s="00"+s;
		}else if(s.size()==3){
			s="0"+s;
		}
		if(one(s)==1){
			int ans=0;
			bool first=true;
			for(int j=0;j<s.size();j++){
				if(s[j]=='1'){
					if(first==true){
						ans=a[j+1];
						first=false;
					}else{
						ans&=a[j+1];
					}
				}
			}
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
}
