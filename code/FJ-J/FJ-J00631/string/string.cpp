#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
int a[200010];
char c[200010];
int n;
int len=0;
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	io;
	cin>>n;
	for(int i=1;i<=n;i++){
		string ch;
		cin>>a[i];
		cin>>ch;
		//cout<<a[i]<<' '<<ch;
		for(int j=1;j<=a[i];j++) s+=ch;
	}
	//for(int i=0;i<s.size();i++) cout<<s[i]<<' ';
	if(s.size()%2==1){
		int mid=(s.size()-1)/2;
		int l=0,r=s.size()-1;
		int ans=0;
		while(l<mid&&r>mid){
			if(s[l]!=s[r]){
				//cout<<s[l]<<' '<<s[r]<<endl;
				//cout<<l<<' '<<r<<endl;
				//cout<<"------------------"<<endl;
				ans++;
			} 
			l++,r--;
		}
		cout<<ans;
	}
	if(s.size()%2==0){
		int mid=s.size()/2-1;
		int l=0,r=s.size()-1;
		int ans=0;
		while(r-l>=1){
			if(s[l]!=s[r]){
				ans++;
				cout<<s[l]<<' '<<s[r]<<endl;
				cout<<l<<' '<<r<<endl;
				cout<<"------------------"<<endl;	
			} 
			l++,r--;
		}
		cout<<ans;
	}
	return 0;
}
