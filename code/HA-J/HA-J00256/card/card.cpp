#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
string s[maxn];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		string st;
		for(int j=i;j<=n;j++) st+=s[i],st+=" ";
		int k=0;
		while(k<st.size()){
			auto f=st.find(" ",k);
			string p;
			if(f==string::npos){
				
			}else{
				p=substr(k,f-k);
			}
			if(p==s[i]){
				
			}
			auto 
		} 
	}
	return 0;
} 
