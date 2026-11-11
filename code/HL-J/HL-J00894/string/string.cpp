#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		char y;
		scanf("%d %c",&x,&y);
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	long long mi=(s.size()+1)/2;
	long long i=mi-1,j=mi-1;
	long long ans=0;
	if(s.size()%2==0) i++;
	for(;i<s.size()+1,j>=0;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}