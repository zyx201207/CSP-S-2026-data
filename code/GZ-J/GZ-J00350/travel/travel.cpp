//GZ-J00350 贵阳市第三实验中学 郑思成 
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f
#define INF 0x3f3f3f3f3f3f
using namespace std;

bool side[5][5]={{0,1,1,0,0},{1,0,1,0,0},{1,1,0,0,0},{0,0,0,0,1},{0,0,0,1,0}};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool res1=false,res2=false,res3=false,res4=false;
	if(c1==c2){res1=true;}
	cout<<res1;
	string ts1="",ts2="";
	char tss1=s1[2],tss2=s2[2];
	for(int i=0;i<2;i++){
		ts1+=s1[i];
		ts2+=s2[i];
	}
	if(ts1==ts2){res2=true;}
	res2=(res1&&res2);
	cout<<res2;
	int t1,t2;
	if(tss1=='F'){t1=4;}
	else{t1=tss1-'A';}
	if(tss2=='F'){t2=4;}
	else{t2=tss2-'A';}
	res3=side[t1][t2];
	res3=(res2&&res3);
	cout<<res3;
	res4=(res3&&(t2-t1==1||t1-t2==1));
	cout<<res4;
	return 0;
}
