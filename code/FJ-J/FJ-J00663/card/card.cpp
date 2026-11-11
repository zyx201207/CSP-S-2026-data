#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
string s="";
struct P{
	int num,x=500005,cnt=0;//xiabiao,chuxiancishu
	bool cx=0;
}b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].x=min(i,b[a[i]].x);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]].cx){
				s.erase(b[a[j]].x-1,j-b[a[j]].x);
			}
			b[a[j]].cx=1;
			s+=char(a[j]+'0');
		}
		for(int j=0;j<s.length();j++){
			b[s[j]-'0'].cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i].cnt<<" ";
	}
	return 0;
}
