#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e9+10;
int n,len=0;
string s;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int s_end = 1,a;
	char c;
	int cnt = 0;
	for(int i=1;i<=n;i++){ 
		cin>>a>>c;
		len+=a;
		for(int j=s_end;j<=a+s_end;j++){
			s[j]=c;
		}
		s_end+=a;
	}
//	for(int i=1;i<len+1;i++){
//		cout<<s[i];
//	}
//	cout<<len;
	int middle = len/2;
	int ans = 0;
	if(len%2 == 0){
		for(int i=1;i<=middle;i++){
//			cout<<"compare "<<s[i]<<" "<<s[len+1-i]<<endl;
			if(s[i] != s[len+1-i]){
				ans++;
//				cout<<"change:"<<i<<endl;
			}
		}
	}
	if(len%2 == 1){
		for(int i=1;i<=middle;i++){
//			cout<<"compare "<<s[i]<<" "<<s[len+1-i]<<endl;
			if(s[i] != s[len+1-i]){
				ans++;
//				cout<<"change:"<<i<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
	
	
}
