#include<bits/stdc++.h>
using namespace std;
int c11,c22;
char s11[3],s22[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c11>>s11>>c22>>s22;
	if(c11==c22){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s11[0]==s22[0]&&s11[1]==s22[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s11[2]>=68&&s22[2]>=68)^(s11[2]<=667&&s22[2]<=67)){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if((s11[2]-s22[2]==1&&s11[2]!=68)^(s11[2]-s22[2]==-1&&s11[2]!=67)){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}//Trick||Treat!
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

