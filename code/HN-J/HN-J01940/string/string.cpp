#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s;
	if(n==1){
		cout<<0;
		return 0;
	}
	int a[n]={0}; 
	for(int i=0;i<n;i++){
		string x;
		cin>>a[i]>>x;
		s+=x;
	}
	int j=s.size()-1;
	for(int i=0;i<n/2;i++){
		if(s[j]!=s[i]){
			ans+=a[i];
			//cout<<a[i]<<" "<<a[j]<<" ";
		}
	}
	cout<<ans;
	return 0;
}/*
我了个雷，没想到第二题竟然做的比第一题快，但好像有点死了，大样例会爆栈，哦不不不，我无疑是喷怒的，希望姥爷评测机会给点分吧 大概68的样子 
oh my god 5*1e8就会爆炸，题目是2*1e5*1e9，额，又被看穿了吗，感觉脸上开始长尸斑了 
额，加了个特判，希望能拿点分吧QpQ 
哇塞，我简直是个天才，睡了一觉出题人托梦给我正解，在最后16分钟A了，老师是不是你一辈子，依旧睡觉想出正解
一开始是直接双循吧x存进s，但我一想，不悦，最大2e5*1e9双循绝对会爆，所以我就睡了一觉，某位前辈告诉我要直接把数存到a中，最后再去给他调用，再去给他加到ans里，这样时间复杂度为O(1.5n)，对比之前的O(n^2)可是遥遥领先
考试一定要睡觉，这样才能想出正解
*/
