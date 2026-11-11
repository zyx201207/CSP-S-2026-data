#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char s[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string ss="";
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
		for(int j=1;j<=a[i];j++){
			ss+=s[i];
		}
	}
	int mid=ss.size()/2+1,ans=0;
	ss=' '+ss;
	int l=mid,r=mid;
	if(ss.size()-1%2==0){
		r++;
	}
	while(l>0){
		if(ss[l]!=ss[r]) ans++;
		l--,r++;
	}
	cout<<ans;
	return 0;
} 
