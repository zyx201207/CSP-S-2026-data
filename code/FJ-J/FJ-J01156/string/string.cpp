#include <bits/stdc++.h>
using namespace std;
long long n,a[1000005],size=0,ans=0;
string c,s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("stirng.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    cin>>c[i];
	    for(int j=1;j<=a[i];j++){
	    	s+=c[i];
	    	size++;
		}
	}
	t=s;
	reverse(t.begin(),t.end());
	if(t==s){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=size/2;i++){
		for(int j=n;j>=size/2;j--){
			if(s[i]!=s[j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}

