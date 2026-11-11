#include<bits/stdc++.h>
using namespace std;
int n,a,ans=0,l;
string s="";
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++) s+=c;
		l+=a;
	}
	int i=0,j=l-1;
	if(l%2==0){
		while(i-j!=1){
			if(s[i]!=s[j]) ans++;
			i++;
			j--;
		}
	}
	else{
		while(i!=j){
			if(s[i]!=s[j]) ans++;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
