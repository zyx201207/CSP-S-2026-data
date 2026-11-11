#include <bits/stdc++.h>
using namespace std;
int n;
string target;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//1.凭借字符串、
	cin>>n;
	char s = ' ';
	int shu  =0;
	for(int i=0;i<n;i++){
		cin>>shu>>s;
		target+=string(shu,s);
	}
	
	long long l=0,r=target.size()-1,cnt=0;//l为头指针，r为尾指针
	while(l<=r){
		if(target[l]!=target[r]){
			cnt++;
		}
		l++;r--;
	}
	cout<<cnt;
	return 0;
}