#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//牛魔CCF看不懂题是真的,T2给普及-吧 
	//原谅我没听过语文课 
	//不管了先Rp++;和xyh99 
	int ccf;
	cin>>ccf;long long ans=0;
	vector<char>a;
	while(ccf--){
		long long a1;char n;
		cin>>a1;
		cin>>n;
		while(a1--)a.push_back(n);
		//写完输入就好累了 ，这不会写输入就爆TLE了吧 
	}for(int i=0;i<a.size()/2;i++){
//		cout<<i<<" "<<a.size()-i-1<<endl;
//		cout<<a[i]<<a[a.size()-i-1]<<endl;
		//debug
		if(a[i]!=a[a.size()-i-1]){
			//cout<<1<<endl;
		//debug
			ans++;
		}
	}//cout<<"ans:";
	cout<<ans;
	return 0; 
	//Process exited after 0.7705 seconds with return value 0
	//不知道会不会TLE，应该不会吧，没想到别的做法
	//n=2*10^5 a1<=1*10^9;
	//O(n*a1/2)
	//Omax=(100,000,000,000,000)
	//百万亿？神了，可能是我有病吧 
	//22min切出
	//花费10min读题呃呃
	//感觉kkk和chen_zhe会给入门呃呃
	//csp-j1估计得300+分
	//想xyh了
	//神秘ccf想要证书钱可以直接抢的
	//别掉我csp含金量（其实本来也没什么含金量（bushi 
	
}/*
2
2 a
3 a
*/
/*
3
2 a
2 b
1 c
*/
