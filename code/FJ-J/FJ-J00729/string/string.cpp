#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		while(a--) s+=c;
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) cnt++;
		l++;
		r--;
	}
	printf("%d",cnt);
	return 0;
}
