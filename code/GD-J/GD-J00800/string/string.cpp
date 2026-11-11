#include<iostream>
using namespace std;
int a[1145141];
char ch[1145141];
struct lian{
	int l,r;char ch;
}strs[1145141];
char cha[11145141];
//这道题太难了建议降低难度，我不会写 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int sum_len=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		for(int j=sum_len+1;j<=sum_len+a[i];j++) cha[j]=ch[i];
		sum_len+=a[i];
	}
	int ans=0;
	for(int i=1;i<=sum_len/2;i++){
		if(cha[i]!=cha[sum_len-i+1]) ans++;
	}
	cout<<ans;
}
