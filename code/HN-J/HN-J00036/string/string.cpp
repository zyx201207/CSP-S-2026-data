#include<bits/stdc++.h>
using namespace std;
long long n,a[10000050];
char c;
string s;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<a[i];j++){
			s=s+c;
		}
	}
	for(int h=s.size();h>0;h--){
		for(int w=1;w<s.size();w++){
			if(s[h]==s[w]){
				continue;
			}
			else{
				ans++;
				continue;
			}
		} 
	} 
	if(ans<=2){
		cout<<"0";
	}else{
		ans/=2;
		cout<<ans;
	}
	return 0;
}  
