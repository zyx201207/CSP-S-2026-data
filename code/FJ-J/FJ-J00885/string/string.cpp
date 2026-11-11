#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10;
int a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string s;
	int l=0,pd=0;
	char x;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(i==1) x=b[i];
		else{
			if(x!=b[i]) pd=1;
		}
	}
	if(pd==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int l1=1;l1<=a[i];l1++){
			s=s+b[i];
			l++;
		}
	}
	//cout<<s<<endl;
	int ans=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]){
			ans++;
		//cout<<i<<' '<<l-1-i<<" "<<s[i]<<" "<<s[l-1-i]<<" "<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}

