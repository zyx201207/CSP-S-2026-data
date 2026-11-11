#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],pre,fer,l,r,ans;
char b[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>> b[i]; 
	}
	pre=a[l];
	fer=a[r];
	while(l<r){
		if(b[l]!=b[r]){
			ans+= min(pre,fer);
		}
		if(pre>fer){
			pre=pre-fer;
			fer=a[++l];
		}
		else{
			fer=fer-pre;
			pre=a[--r];
		}
	}
	cout<<ans<<endl;
	return 0;
} 
