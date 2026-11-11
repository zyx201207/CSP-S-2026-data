#include<bits/stdc++.h>
using namespace std;
int n,a,ans=0;
long long sum=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	if(sum%2==0){
		int z=s.length()/2-1;
		for(int i=0;i<z;i++){
			if(s[i]!=s[s.length()-1-i]){
				ans++;
			}
		}
		if(s[z]!=s[z+1]){
			ans++;
		}
	}else{
		int z=s.length()/2;
		for(int i=0;i<z;i++){
			if(s[i]!=s[s.length()-1-i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
