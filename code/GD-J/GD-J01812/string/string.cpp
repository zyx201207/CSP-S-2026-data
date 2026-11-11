#include<bits/stdc++.h>
using namespace std;
struct S{
	int len;//这段相同字母有多长， 
	char c;//这段是啥字母 
}s[200005];

int sum_len,n,ans; //字符串的总长 ，有几段数据，答案 

char c[200000005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].len>>s[i].c;
		sum_len+=s[i].len;
	}
	
	int k=1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i].len;j++){
			c[k]=s[i].c;
			k++;
		}
	}
	
	for(int left=1;left<=n/2+1;left++){
		if(c[left]!=c[sum_len+1-left])ans++;
	}
	cout<<ans;
	return 0;
}
