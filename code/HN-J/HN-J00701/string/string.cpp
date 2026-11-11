#include <bits/stdc++.h>
using namespace std;
int a;
char chr[100005];
long long  l[100005];
string make_str(){
	string str;
	int cnt=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<l[i];j++){
			str+=chr[i];
			cnt++;
		}
	}
	return str;
}
int edit(string str){
	int s=str.size();
	int start=0;int end=0;
	if(s%2==0) {
		start=s/2-1;
		end=start+1-1;
	}
	else {
		start=(s-1)/2-1;
		end=start+2-1;
	}
	int cnt=0;
	for(int i=1;i<=s/2;i++){
		if(str[end]!=str[start]){
			cnt++;
		}
		else{
			start--;
			end++;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>l[i]>>chr[i];
	}
	string p=make_str();
	cout<<edit(p);
	return 0;
} 
