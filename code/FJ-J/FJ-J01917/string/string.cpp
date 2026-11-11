#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,num=0;
	char k;
	string s="";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> k;
		num+=a;
		for(int i=0;i<a;i++){
			s+=k;
		}
	}
	int sum=0;
	if(num%2==0){
		for(int i=num/2;i<num;i++){
			if(s[i]!=s[num-i-1]){
				sum++;
			}
		}
	}else{
		for(int i=num/2+1;i<num;i++){
			if(s[i]!=s[num-i-1]){
				sum++;
			}
		}
	}
	cout << sum;
} 
