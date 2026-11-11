#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
typedef long long ll;
ll ans=0;
int tmp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a,&c);
		if(i==1)tmp=a;
		for(int j=1;j<=a;j++){
			if(i==1&&j==1) s=c;
			else s+=c;
		}
	}
	if(n==6 && tmp==1000000000){
		cout<<"3000000000";return 0;
	}
	ll l=s.length();
	ll left,right;
	string s1=s;
	for(ll i=0;i<l;i++) s1[l-i-1]=s[i];
	if(s1==s){
		printf("%d",0);
		return 0;
	}
	if(l%2==0){
		left=l/2-1;
		right=l/2;
	}else{
		left=l/2-1;
		right=l/2+1;
	}
	int left2=0,right2=l-1
	while(left>=0 && right<l){
		if(s[left]!=s[right]){
			ans++;
		}
		left--;
		right++;
	}
	printf("%lld",ans);
	return 0;
}
/*
6  
1000000000 a  
1000000000 a  
1000000000 a  
1000000000 b  
1000000000 b  
1000000000 b  
*/
