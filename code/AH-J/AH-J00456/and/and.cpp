#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
string s[200005];
int ans;


int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i];
		while(t){
			s[i]=char(t%2+48)+s[i];
			t=t/2;
		}
    }
    ans=a[n];
	cout<<ans<<endl;
	return 0;
}

