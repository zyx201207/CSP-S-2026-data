#include<bits/stdc++.h>
using namespace std;
char c;
string s;
long long a[200034],ans,cnt,n,op,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>op;
	if(op<=2000){
		for(int i=1;i<=op;i++){
			cin>>n>>c;
			for(int i=1;i<=n;i++){
				s+=c;
			} 
		} 
	    for(int i=0;i<s.size()/2;i++){
	    	if(s[i]!=s[s.size()-i-1]) ans++;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=op;i++){
			cin>>n>>c;
			sum+=n;
		} 
		cout<<sum/2;
	} 
	return 0;
}
