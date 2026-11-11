//GZ-J00203 罗家珍 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll const maX=200005;

ll n,a[maX],k,cnt=0,y;
string s,b; 
bool x=false;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n; 
	
	for(ll i=0;i<n;i++) cin>>a[i]>>s[i];
	
	if(n==1){
		cout<<0;
		return 0;
	}
	
	x=false;
	
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(s[i]==s[j]) x=true;
			else x=false;
		}
	}
	if(x) {
		cout<<0;
		return 0;	
	}
	
	
	
	for(ll i=0;i<n;i++){
		for(ll j=0;j<a[i];j++){
			b+=s[i];
		}
	}
	k=b.size(); 
	y=(b.size())/2;

	for(ll i=0;i<k;i++){
			if(b[i]==b[k-i-1]) {
			x=true;
			if(k-i-1==y){
				break;
			}
			}else {
				b[k-i-1]=b[i];
				cnt++;
			}
		}
	
	if(x) cout<<cnt;
	
	
	
	return 0;
}
