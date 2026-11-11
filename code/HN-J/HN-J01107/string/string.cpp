#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans,sum;
char c[200005],s[700000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	for (int i=1;i<=n;i++){
	    for (int j=1;j<=a[i];j++){
	    	s[++ans]=c[i];
		}
	}
	for (int i=1;i<=ans/2;i++){
		if (s[i]!=s[ans-i+1]) sum+=1;
	}
	cout<<sum;
	return 0;
}
