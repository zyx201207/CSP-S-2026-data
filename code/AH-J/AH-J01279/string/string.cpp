#include<bits/stdc++.h>
using namespace std;
long long n,i,a[1000010];
char c[1000010];
string s,t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
     ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long cnt=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(i=s.size();i>=1;i--){
		t+=s[i];
	}
	for(i=1;i<=s.size();i++){
        if(t==s){
            cout<<0;
            break;
        }else if(t[i]!=s[i]){
            cnt++;
        }
	}
	cout<<cnt;
	return 0;
}
