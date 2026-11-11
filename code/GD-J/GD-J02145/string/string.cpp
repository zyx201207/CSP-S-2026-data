#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int len[maxn];
char ch[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>len[i]>>ch[i];
	int Left=1,Right=n;
	long long ans=0;
	while(Left<Right){
		int MinLen=min(len[Left],len[Right]);
		if(len[Left]==len[Right]){
			ans+=len[Left]*(ch[Left]!=ch[Right]); 
			Left++;Right--;
		}else if(len[Left]<len[Right]){
			ans+=MinLen*(ch[Left]!=ch[Right]); 
			len[Right]-=MinLen;Left++;
		}else{
			ans+=MinLen*(ch[Left]!=ch[Right]); 
			len[Left]-=MinLen;Right--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
