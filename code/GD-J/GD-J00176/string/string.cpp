#include<bits/stdc++.h>
using namespace std;
int n,a,s[100005],aa,ans;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int k=0;
	while(n--){
		cin>>a>>x;
		for(int i=k;i<a+k;i++) s[i]=x-'a';
		aa+=a,k+=a;
	}
	for(int i=0;i<=(aa-1)/2;i++){
		if(s[i]!=s[aa-i-1]) ++ans;
	}
	cout<<ans;
	return 0;
}
