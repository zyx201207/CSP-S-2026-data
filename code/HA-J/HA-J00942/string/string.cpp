#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
char c[200005];
string s;
ll cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    ll len=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	len+=a[i];
    	for(int j=1;j<=a[i];j++){
    		s+=c[i];
		}
	}
	ll i=0,j=len-1;
	while(i<=j){
		if(s[i]!=s[j]){
			cnt++;
		}
		i++;
		j--;
	} 
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
