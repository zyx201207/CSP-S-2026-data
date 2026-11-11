#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	 
	string sss = "";//未回文的字符串总和 
	string sa="";//逆序sss 
	string ss = "";//单个字符串 
	int sum = 0;
	for(int i = 0;i < n;i++){
		int x;
		cin >> x;
		char c;
		cin >> c;
		
		for(int j = 0;j < x;j++){
			ss+=c; 
		}
		int len2 = ss.size();
		for(int i = 0;i < len2;i++){
			sss+=ss[i];
		}
	} 
	int len3 = sss.size();
	sa = sss;
	if(len3%2 == 1){
		len3/=2;
		len3+=1;
	}else {
		len3/=2;
	}
	reverse(sa.begin(),sa.end()-1);

	for(int i = 0;i < len3;i++){
		if(sa[i] != sss[i]){
			sum ++;
		}else{
			continue;
		}
	} 
	cout << sum;
	return 0;
} 

