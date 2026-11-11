#include<bits/stdc++.h>
using namespace std;
long long  n,a[200005],ans;
long long m;
string s,c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    	cin>>n;
    	for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
			m+=a[i];
		}
        for(int i=0;i<=m/2-1;i++){
			if(s[i]!=s[m-i-1]){
				ans++;
			
			}
		}
		cout<<ans;
		return 0;
}
