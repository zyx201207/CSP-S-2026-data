#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005],mx,ans;
char s;
string res;
ll sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s;
		for(int j=1;j<=a[i];j++) res+=s;
	}
	int l=res.size();
	for(int i=0;i<l/2;i++){
		if(res[i]!=res[l-i+1]) ans++;
	}
	 cout<<ans;
	
	return 0;
}

