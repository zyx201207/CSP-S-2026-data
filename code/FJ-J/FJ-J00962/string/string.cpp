/*
自制样例 1
2
1 a
4 b
abbbb
bbbba
2=4+1-(4-1)
自制样例 2
4
7 a
8 b
9 c
1 d
1  2  3  4
7  15 24 25
25 18 10 1
4  3  2  1
aaaaaaabbbbbbbbcccccccccd
dcccccccccbbbbbbbbaaaaaaa
5=15-10
自制样例 3
2
3 a
3 b
1  2
3  6
6  3
2  1
aaabbb
bbbaaa
3=(3+3)

不能直接存字符串，会爆炸 
200005
600015
*/
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int cnt=1,last;
	bool f=0,f1=0;
	for(int i=1;i<=n;i++){
		int e;
		char c;
		scanf("%d",&e);
		getchar();
		scanf("%c",&c);
//		cin>>c;
		for(int i=1;i<=e;i++)s+=c;
	}
//	cout<<s;
	for(int i=s.size()-1;i>=0;i--)s2+=s[i];
	for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s2[s2.size()-i])ans++;
	}
	cout<<ans;
	return 0;
}

