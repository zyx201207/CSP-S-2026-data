#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int flag=0;
string a,k,b,o;

int main(){
	freeopen("travel.in","r",stdin);
	freeopen("travel.out","w",stdout);
	cin >> a >> k;
	cin >> b >> o;
	if(a!=b)	
	{
		cout << "0000";
		return 0;
	}
	for(int i=0;i<=1;i++)
		if(k[i]!=o[i])
		{
			cout << "1000";
			return 0;
		}
	if('A'<=k[2] &&k[2]<='C' && 'A'<= o[2]&&o[2]<='C')
		flag=1;
	if('D'<=k[2] && k[2]<='F' && 'D'<=o[2] && o[2]<='F')
		flag=1;
	if(flag==0)
	{
		cout << "1100";
		return 0;
	}
	if(k[2]+'1'==o[2]+'0' && k[2]!='C')
		cout << "1111";
	else if(k[2]-'1'==o[2]+'0' && k[2]!='D')
		cout << "1111";
	else 
		cout << "1110";
	return 0;
}
