#include <bits/stdc++.h>
using namespace std;
string S;
char c;
int n,a,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	S+=' ';
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			S+=c;
		}
	}
	for(int i=1;i<=(S.size()-1)/2;i++){
		if(S[i]!=S[S.size()-i+1]){
			ans++;
		}
	}
	cout<<ans;
}
