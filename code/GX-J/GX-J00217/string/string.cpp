#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans=0,b,m=0;
char c[200010];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}		
	}
	b=s.size();
	b--;
	for(int i=1;i<=b/2;i++){
		if(s[i]==s[b-i+1]){
			continue;
		}else{
			ans++;
			
		}
	}
	cout<<ans;
	return 0;
}
