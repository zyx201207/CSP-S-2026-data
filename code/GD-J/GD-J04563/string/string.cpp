/*
小 R 有一个长度为 L 的字符串 S = s1 . . . sL，其中只包含小写英文字母。小 R 发
现，虽然 S 可能很长，但它可以分成 n 个连续的段，其中第 i (1 ≤ i ≤ n) 段由 ai 个小
写英文字母 ci 构成。把这 n 段依次拼接起来便得到 S，因此 L =
∑n
i=1 ai。相邻两段中
的字符可以相同。
小 X 喜欢回文串。若一个字符串反转后与原字符串相同，就称它是回文串，例如
aba、abba 都是回文串，而 aabbc 不是。也就是说，字符串 S 是回文串，当且仅当对
于所有 i (1 ≤ i ≤ L)，均有 si = sL+1?i。
小 X 想让小 R 把 S 改成回文串。小 R 可以将 S 中任意一个位置的字符修改成任
意小写英文字母。他想用尽量少的修改满足小 X 的要求。
你需要帮助小 R 求出，他最少需要修改多少个位置的字符，才能将 S 改成回文串。
【输入格式】
从文件 string.in 中读入数据。
输入的第一行包含一个正整数 n。
输入的第 i + 1 (1 ≤ i ≤ n) 行包含一个正整数 ai 和一个小写英文字母 ci。
【输出格式】
输出到文件 string.out 中。
输出一行一个整数，表示小 R 最少需要修改多少个位置的字符，才能将 S 改成回
文串。
感觉暴力这次被制裁了
这个要线性以下了啊
根本写不出来 
*/
#include<bits/stdc++.h>
using namespace std;
long long n;
string x;
long long a;
char c;
long long ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
    	cin>>a>>c;
    	for(long long i=0;i<a;i++){
    		x=x+c;
		}
	}
	long long l=0,r=x.size()-1;
	while(l<=r){
		if(x[l]==x[r]){
			l++;
			r--;
			continue;
		}else{
			ans++;
			cout<<x[l]<<" "<<x[r];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
