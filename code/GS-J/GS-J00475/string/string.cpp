#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
int n;
cin>>n;
long long l=0,count=0,i,a;
char c;
string s;
for(i=1;i<=n;i++){
	cin>>a>>c;
	for(int j=1;j<=a;j++)s+=c;
	l+=a; 
}
	for(long long k=0,p=l-1;k<=(l+1)/2&&p>=(l+1)/2;){
		if(s[k]!=s[p]){
			s[p]=s[k];
			count++;
		}
		p--;
		k++;
	}
	cout<<count;
    return 0;
}
