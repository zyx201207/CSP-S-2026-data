#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1])printf("0000");
	else{
		printf("1");
		if(s1[0]!=s2[0]||s1[1]!=s2[1])printf("000");
		else{
			printf("1");
			char ch1=s1[2],ch2=s2[2];
			if(ch1>='A'&&ch1<='C'){
				if(ch2>='A'&&ch2<='C'){
					printf("1");
					if(ch1=='A'&&ch2=='B')printf("1");
					else if(ch1=='B'&&ch2=='A')printf("1");
					else if(ch1=='C'&&ch2=='B')printf("1");
					else if(ch1=='B'&&ch2=='C')printf("1");
					else printf("0");
				}else printf("00");
			}
			if(ch1>='D'&&ch1<='F'){
				if(ch2>='D'&&ch2<='F'){
					printf("11");
				}else printf("00");
			}
		}
	}
	return 0;
}

/*
题目名称旅游回文串按位与纸牌游戏
题目类型传统型传统型传统型传统型
目录travel string and card
可执行文件名travel string and card
输入文件名travel.in string.in and.in card.in
输出文件名travel.out string.out and.out card.out
每个测试点时限1.0 秒1.0 秒1.0 秒1.0 秒
内存限制1024 MiB 1024 MiB 1024 MiB 1024 MiB
测试点数目20 25 20 25
测试点是否等分是是是是
提交程序源文件名
对于C++ 语言travel.cpp string.cpp and.cpp card.cpp
编译选项
对于C++ 语言-O2 -std=c++14 -static
*/
//freopen("travel.ans","W",stdin);
