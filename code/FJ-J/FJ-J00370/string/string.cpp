#include<bits/stdc++.h>
using namespace std;
long long a[20005],ans=0,w=0,r=0;
string s[20005],q[20005];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		w+=a[i];
		for(int j=1+a[i-1];j<=a[i];j++){
		   	q[j]==s[j];
		   	w++;
		}
	}
	int m=w;
	for(int i=1;i<=w;i++){
		if(q[i]!=q[m]){ans++;
		}
		m--;
	}cout<<ans;
	return 0;
}
