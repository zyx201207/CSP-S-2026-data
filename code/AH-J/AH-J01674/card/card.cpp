#include<bits/stdc++.h>
#define I using
#define AK namespace
#define CSP std
I AK CSP;
//My Luogu name:Fat_Catt
int n,m,a[114514],t[114514],ans[114514]={0};
int check(int x,int k){
	for(int i=1;i<=k;i++){
		if(t[i]==k)return i;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=i;j<=n;j++){
			int c=check(a[j],k);
			if(c==-1){
				t[k]=a[j];
				k++;
			}
			else{
				t[c]=a[j];
				k=c+1;
			}
		}
		for(int j=i;j<=k;j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
2026 CSPJ （流）游（水）记（账） 
8：17
紧张ing……原来CSP的压缩包还有密码的吗 
真的有人CSP用虚拟机吗（疑惑） 
(我弟坐在我右边两个位置欸)
8:58 
恭喜我AC T1！一遍过！
9：00
T2好难啊 
9：07
报告长官，我已发现T2规律，感觉良好！
e大概就是字符串反过来剩下自己找找不到就是真没招了qwq 
9:16
耶T2做出来了
9：17
错了qwq 
9：18
条过之后又错了
9:21
知道怎么条了
O(N)万岁！！！！！！！！ 
9:35
我真没招了
10:10
没写完但估计只有100+68+65+0=233（雾）pts
去年AH要260分1=
祈祷ing……
希望今年AH 1= 只要220吧qwq 

在此鸣谢Accepted0620当我的同桌（bushi） 
CCF把我弟放在我右边两个位置
kkk建立洛谷（ 
10:46
写完了T2的暴力，O(N*max(a[i])),200000000也能过，不知道为什么 
11:04
T3打表打了一半了，感觉打表好啊，打表妙啊！
11:31
打表已经打完了，刚才去上了个厕所
估计有100+68+50+15=233（怎么还是233） 
11:46
我感觉我要坠机了 
11:59
拜拜了兄弟们，100+68+50+0，尽力了，希望有人把我搬到神秘代码大赏里面吧，谢谢！ 
*/
/*
ni shuo ni bu xiang zai zhe li , wo ye bu xiang zai zhe li , dan tian hei de tai kuai xiang zou zao jiu lai bu ji , o wo ai ni, ke xi guan xi bian cheng mei guan xi wen ti shi mei wen ti , yu shi wo men ji xu.
na qi bi , xiang xie dian don xi , yi wei shi wu qi neng sheng zhang zheng E!(忘词了) 
*/
