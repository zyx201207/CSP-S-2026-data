#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,ans=0;
	int a[200005]={0};
	string c,str;
	str[0]='#';
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			str+=c[i];
			if(i==1&&j==1)str+=c[i];
		}
	}
	int len=(int)str.length()-1;
	//for(int i=1;i<=len;i++)cout<<str[i];
	//cout<<endl;
	for(int i=1;i<=len;i++){
		if(str[i]==str[len+1-i])continue;
		else{
			ans++;
			str[i]=str[len+1-i];
		}
	}
	cout<<ans<<endl;
	//for(int i=1;i<=len;i++)cout<<str[i];
	return 0;
}
