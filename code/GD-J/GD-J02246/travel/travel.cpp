#include<bits/stdc++.h>
using namespace std;
struct xiang{
	char aaa1,aaa2;
}ooo,ppp;
struct zuo{
	char bbb1,bbb2,bbb3;
}kkk,lll;
char wuwuwu;
//freopen("travel.out","w",stdout);
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ooo.aaa1>>ooo.aaa2>>kkk.bbb1>>kkk.bbb2>>kkk.bbb3>>ppp.aaa1>>ppp.aaa2>>lll.bbb1>>lll.bbb2>>lll.bbb3;
    
    cout<<(ooo.aaa1==ppp.aaa1 and ooo.aaa2==ppp.aaa2);
    cout<<((ooo.aaa1==ppp.aaa1 and ooo.aaa2==ppp.aaa2) and (kkk.bbb1==lll.bbb1 and kkk.bbb2==lll.bbb2));
    cout<<((ooo.aaa1==ppp.aaa1 and ooo.aaa2==ppp.aaa2) and (kkk.bbb1==lll.bbb1 and kkk.bbb2==lll.bbb2) and (((kkk.bbb3-'A')<3 and (lll.bbb3-'A')<3) or ((kkk.bbb3-'A')>2 and (lll.bbb3-'A')>2)));	
    cout<<((((lll.bbb3-'A')-(kkk.bbb3-'A'))==1 or ((lll.bbb3-'A')-(kkk.bbb3-'A'))==-1) and (ooo.aaa1==ppp.aaa1 and ooo.aaa2==ppp.aaa2) and (kkk.bbb1==lll.bbb1 and kkk.bbb2==lll.bbb2) and (((kkk.bbb3-'A')<3 and (lll.bbb3-'A')<3) or ((kkk.bbb3-'A')>2 and (lll.bbb3-'A')>2)));
	return 0;
}//luogu.com.cn
//直接硬算应该没问题吧 
