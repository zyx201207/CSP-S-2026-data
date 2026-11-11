#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000],s[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>a[i]>>c;
        for(int j=1;j<=i;j++){
			s[j--]='a';
			ans++;
		}
	}
	cout<<ans;
    return 0;
}
