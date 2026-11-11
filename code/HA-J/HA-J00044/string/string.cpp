#include<bits/stdc++.h>
using namespace std;
char tin[1000000005];
int ti=1,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			tin[ti]=c;
			ti++;
		}
	}
	ti=ti-1;
	for(int i=1;i<=ti/2;i++){
		if(tin[i]!=tin[ti-i+1]){
			ans++;
		}
	}
	cout<<ans;
	//Trick||Treat!
	//Trick||Treat!
	//祝我RP++！
	//mhh保佑我不要有任何猎奇的问题
	//lz保佑我
	//诚心祈祷。。。
	//！ ！ ！
	///  /  /
	//tbyz再创辉煌吧！
	//我真写不动了，防爆零手册无力了
	//明天就不会登zyzoj了lz别销我号呗
	//鬼知道我能不能继续学
	//dzt保佑
	//神秘 milk dragon 保佑 
	//ZYZ先生保佑啊
	//我还想去一高 
	return 0;
}

