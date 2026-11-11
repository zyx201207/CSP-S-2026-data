#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long num;
	char ch;
}s[200005];
int n;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].ch;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<=r){
		char x=s[l].ch,y=s[r].ch;
		s[l].num--,s[r].num--;
		if(s[l].num<=0)l++;
		if(s[r].num<=0)r--;
		if(x!=y)ans++;
	}
	cout<<ans;
	return 0;
}
