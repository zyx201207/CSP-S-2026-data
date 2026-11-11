//card
//T1 travel花了30分钟AC T2 string花了120分钟WA T3 and花了20分钟WA T4 card花了15分钟WA 甚至不如去年了 去年至少AC了T1 number 和T2 seat
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long cards[564444];
long long cc[364444];
vector<long long>table;
long long read(){
	long long f=1;
	long long res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		long long kk=ch-48;
		res=res*10+kk;
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	n=read(),m=read();
	for(long long i=1;i<=n;i++)cards[i]=read();
//	long long count=1;
	for(long long t=1;t<=n;t++){
		table.erase(table.begin(),table.end());
		for(long long i=t;i<=n;i++){
			if(find(table.begin(),table.end(),cards[i])!=table.end()){
				table.erase(find(table.begin(),table.end(),cards[i]),table.end());
				table.push_back(cards[i]);
			}
			else table.push_back(cards[i]);
		}
		for(auto p:table)cc[p]++;
	} 
	for(long long i=1;i<=m;i++){
		print(cc[i]);
		putchar(' ');
	}
}
