#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long k;
		string a;
		cin>>k;
		cin>>a;
		for(int i=1;i<=k;i++){
			s+=a;
		}
        m+=k;
	}
    for(int i=0;i<(m/2);i++){
        if(s[i]!=s[m-1-i]){
            ans++;
        }
    }
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
