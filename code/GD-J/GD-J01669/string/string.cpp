#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int num[N];
char ch[N];
int main(){
	ios::sync_with_stdio(true);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>num[i]>>ch[i];
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		int t=min(num[i],num[j]);
		if(ch[i]!=ch[j])
		  ans+=t;
		num[i]-=t;
		num[j]-=t;
		if(num[i]==0)
		  i++;
		if(num[j]==0)
		  j--;
	}
	cout<<ans;
	return 0;
}
