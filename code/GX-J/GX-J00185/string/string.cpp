#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string reverse(string a){
	long long tmp=a.size();
	string tmp2="";
	for(long long i=tmp;i>=0;i--){
		tmp2+=a[i];
	}
	return tmp2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,cut=0,g=1;
	cin>>n;
	long long tmp[n]={0};
	string tmp1="",tmp2[n],tmp3;
	for(long long i=0;i<n;i++){
		cin>>tmp[i]>>tmp2[i];
		if(tmp[i]>10000000){
			g=10000000;
			tmp[i]/=10000000;
		}
		for(long long j=0;j<tmp[i];j++){
			tmp1+=tmp2[i];
		}
	}
	
	if(tmp1==reverse(tmp1)){
		cout<<0;
		return 0;
	}
	
	tmp3=tmp1;
	for(long long i=0;i<long(tmp1.size());i++){
		if(tmp3[i]!=tmp3[tmp1.size()-i-1]){
			tmp3[i]=tmp3[tmp1.size()-i-1];
			cut++;
		}
	}
	cout<<cut*g;
}
