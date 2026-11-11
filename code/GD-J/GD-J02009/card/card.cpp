#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,m,a[N],sb=1,b[N],vis,f;
signed main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	cin>>n>>m;
	for(int i;i<=n;i++){
		cin>>a[i];
	}
	string s;
	for(int i=0;i<n;i++){
		for(int j=0;i<=n;j++){
		bool v=0;
		for(int k=0;k<s.size();k++){
			if(s[k]==a[j]){
				v=1;
				s[k]=1;
			}
			if(v){
				s[k]=0;
			}
		}
		if(f==0){
			s+=v;
		}
		for(int j=0;j<=n;j++){
			cout<<s;
		}
		}
	}
}
