#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a;
char c;
string b;
int n;
unsigned long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n==1)cout<<0;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
			b+=c;
		}
    }
    for(int i=0;i<b.length()/2;i++){
		if(b[i]!=b[b.length()-i-1]){
			ans++;
		}
	}
	cout<<ans;
    return 0;
}
