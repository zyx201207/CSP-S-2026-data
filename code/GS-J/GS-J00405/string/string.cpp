#include <bits/stdc++.h>
using namespace std;
long long n;
vector<string> fuchuan;

long long test1(){
	long long deal=0;
	long long l=0,r=fuchuan.size()-1;
	while(l<=r){
		if(fuchuan[l]!=fuchuan[r]){
			deal+=1;
		}
		l+=1;
		r-=1;
	}
	return deal/2;
}//判断是不是回文 

long long test2(){
	long long deal=0;
	long long l=0,r=fuchuan.size()-1;
	while(l<=r){
		if(fuchuan[l]!=fuchuan[r]){
			deal+=1;
		}
		l+=1;
		r-=1;
	}
	return deal;
}//判断是不是回文 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	long long deal=0;
	for(long long i=1;i<=n;++i){
		long long w;
		cin>>w;
		string tmp;
		cin>>tmp;
		for(long long j=1;j<=w;++j){
			 fuchuan.push_back(tmp);
		}
	}

	if(n/2==0){
		cout<<test1();
	}
	else{
		cout<<test2();
	} 
	return 0;
}
