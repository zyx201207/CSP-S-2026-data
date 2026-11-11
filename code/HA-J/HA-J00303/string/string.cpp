#include<bits/stdc++.h>
using namespace std;
int n,z,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;
		char v;
		cin>>c>>v;
		z+=c;
		for(int i=1;i<=c;i++){
			s+=v;
		}
	}
	for(int i=1,j=z;i<=z/2 and j>=z/2+1 and i!=j ;i++,j--){
		if(s[i-1]!=s[j-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
             