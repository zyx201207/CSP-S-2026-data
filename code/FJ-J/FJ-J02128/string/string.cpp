#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>s[i];
	}
	int i=1,j=n;
	while(i<j){
		if(s[i]!=s[j]) ans+=min(a[i],a[j]);
		a[i]-=min(a[i],a[j]);
		a[j]-=min(a[i],a[j]);
		if(a[i]==0) i++;
		if(a[j]==0) j--; 
	}
	cout<<ans;
	return 0;
}
