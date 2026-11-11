#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],ans;
char c[2000005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];	
		}
	}
	if(s.size()%2==0){
		for(int i=0,j=s.size()-1;i<s.size()/2,j>s.size()/2;i++,j--){
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}
	else{
		for(int i=0,j=s.size()-1;i<s.size()/2+1,j>s.size()/2;i++,j--){
			if(s[i]!=s[j]){
				ans++;
			}
		}		
	}
	cout<<ans;
	return 0;
}
