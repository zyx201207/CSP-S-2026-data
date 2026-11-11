//GZ-J00379 兴义市弘毅中学 刘俊池  
#include <bits/stdc++.h>
using namespace std;
long long n,l[200005],L,ans,zc,z; 
char a[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i]>>a[i];
		L+=l[i];
		for(int j=0;j<l[i];j++){
			s+=a[i];
		}
	} 
	if(L%2==0){
		z=L/2-1;
		for(int i=0;i<=z;i++){
			if(s[i]!=s[L-i-1]){
				ans++;
			}
		}
	}else{
		z=L/2;
		for(int i=0;i<z;i++){
			if(s[i]!=s[L-i-1]){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
