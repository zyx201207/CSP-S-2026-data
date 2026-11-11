#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
int sum=0;
string s,t;
void _string(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string y;
		cin>>x;
		cin>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[j]!=s[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--){
		_string();
	}
	return 0; 
} 
