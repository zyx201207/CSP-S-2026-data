#include<bits/stdc++.h>
using namespace std;
struct jinz2{
	int name,num1;
	string j;
};
jinz2 jinz[288888];
bool cmp(jinz2 a,jinz2 b){
	if(a.num1!=b.num1) return a.num1>b.num1;
	return a.name>b.name;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,cnt1=0,MAX=2147483647;
	cin>>a>>b;
	for(int x=0;x<a;x++){
		cin>>jinz[x].name;
		int cnt=jinz[x].name;
		while(cnt!=0){
			cnt1+=cnt%2;
			jinz[x].j+=char(cnt%2+'0');
			cnt/=2;
		}jinz[x].num1=cnt1;
		cnt1=0;
	}sort(jinz,jinz+a,cmp);
//	for(int x=0;x<a;x++){
//		cout<<jinz[x].name<<' '<<jinz[x].num1<<' '<<jinz[x].j<<endl;
//	}
	for(int x=0;x<b;x++){
		MAX&=jinz[x].name;
	}cout<<MAX;
	return 0;
}
