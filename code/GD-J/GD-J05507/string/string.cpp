#include<bits/stdc++.h>
using namespace std;
struct str{
	char ch;
	int num;
};
str s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int u=1;u<=n;u++){
		cin>>s[u].num>>s[u].ch;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int l=1,r=n,ans=0;
	while(!(l==r||(r-l==1&&s[l].num==0&&s[r].num==0))){
		if(s[r].ch!=s[l].ch){
			ans+=min(s[l].num,s[r].num);
			s[l].num-=min(s[l].num,s[r].num);
			s[r].num-=min(s[l].num,s[r].num);
		}
		else{
			s[l].num-=min(s[l].num,s[r].num);
			s[r].num-=min(s[l].num,s[r].num);
		}
		if(s[l].num==0){
			l++;
		}
		if(s[r].num==0){
			r--;
		}
	}
	cout<<ans;
	return 0;	
} 
