#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool flag=1;
int cnt[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	//两张车票对应的座位是否在同一节车厢；
	for (int i=0;i<=1;i++){
		if (a[i]==c[i]) continue;
		else{
			flag=0;
			cout<<"0000";
			return 0;
		} 
	}
	if (flag) cnt[0]=1;
	//两张车票对应的座位是否在同一节车厢的同一排；
	if (cnt[0]==1 && b[1]==d[1] && b[0]==d[0]) cnt[1]=1;
	else cnt[1]=0;
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧； 
	if (cnt[0]==1 && cnt[1]==1 && b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C' || b[2]>='D' && b[2]<='E' && d[2]>='D' && d[2]<='E') cnt[2]=1;
	else cnt[2]=0;
	//两张车票对应的座位是否相邻。
	bool flag=1;
	if (cnt[0]==1 && cnt[1]==1 && cnt[2]==1 && (b[2]=='A' && d[2]=='B' || b[2]=='B' && d[2]=='C' || b[2]=='D' && d[2]=='E' || b[2]=='B' && d[2]=='A' || b[2]=='C' && d[2]=='B' || b[2]=='E' && d[2]=='D')) cnt[3]=1;
	else cnt[3]=0;
	cout<<cnt[0]<<cnt[1]<<cnt[2]<<cnt[3];
	return 0;
} 
