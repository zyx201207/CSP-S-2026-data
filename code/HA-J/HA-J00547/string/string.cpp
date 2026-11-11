#include<bits/stdc++.h>
using namespace std;
int n;
int num=0;
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			num++;
			s[num]=c;
		}
	}
	int ans=0;
	for(int i=1;i<=num/2;i++){
		if(s[i]==s[num-i+1]){
			ans=ans;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
