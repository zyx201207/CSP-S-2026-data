#include<bits/stdc++.h>
using namespace std;
long long n,t[200010],dd[200010];
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>s[i];
		dd[s[i]-'a'+1]++;
		
	}
	long long ans=0;
	for(int l=1,r=n;l<=r;){
		if(s[l]!=s[r]){
			if(t[l]<t[r]){
				l++;
				t[r]-=t[l];
				ans+=t[l];
			}
			else{
				r--;
				t[l]-=t[r];
				ans+=t[r];
			}
			
		}
		else{
			if(t[l]<t[r]){
				l++;
				t[r]-=t[l];
			}
			else{
				r--;
				t[l]-=t[r];
			}
		}
	}
	cout<<ans; 
	return 0;
}
