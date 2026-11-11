#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt;
struct str{
	long long a;
	char c;
}str[100010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>str[k].a>>str[k].c;
	}
	int i=1,j=n;
	while(i<j)
	{
		if(str[i].c==str[j].c){
			if(str[i].a>str[j].a){
				str[i].a-=str[j].a;
				str[j].a=0;
			}
			if(str[i].a==str[j].a){
				str[i++].a=0;
				str[j--].a=0;
			}
			if(str[i].a<str[j].a){
				str[j].a-=str[i++].a;
				str[i++].a=0;
			}
		}
		else {
			if(str[i].a>str[j].a){
				str[i].a-=str[j].a;
				cnt+=str[j].a;
				str[j--].a=0;
			}
			if(str[i].a==str[j].a){
				cnt+=str[i].a;
				str[i++].a=0;
				str[j--].a=0;
			}
			if(str[i].a<str[j].a){
				str[j].a-=str[i].a;
				cnt+=str[i].a;
				str[i++].a=0;
			}
		}
	}
	cout<<cnt;
	return 0;
}
