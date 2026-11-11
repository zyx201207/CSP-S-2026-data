#include<bits/stdc++.h>
using namespace std;
int s[200005],c,n,m,d,num=0,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin >> s[i];
	for(int a=1;a<=n;a++)
		for(int d=a+1;d<=n;d++)
			num=s[a];
			c=d;
			for(int b=0;b<m;b++) 
				num=num||s[(c+b)];
				if(num>=ans)
					ans=num;
	cout<<ans;
	return 0;
}
