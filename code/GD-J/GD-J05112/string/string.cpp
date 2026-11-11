#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int num=0,n;
bool hw(){
	char z[N];
	int i=num;
	while(i>=0){
		z[num-i]=s[i-1];
		i--;
	}
	for(int j=0;j<=num/2+1;j++){
		if(z[j]!=s[j]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char c;
		cin>>x;
		cin>>c;
		for(int j=0;j<x;j++){
			s[num]=c;
			num++;
		}
	}
	int ans=0,i=0;
	while(1){
		if(hw()){
			break;
		}
		if(s[num-i-1]==s[i]){
			i++;
			continue;
		}
		s[num-i-1]=s[i];
		i++;
		ans++;
	}
	cout<<ans;
	return 0;
}
//2 2 a 3 a
//3 2 a 2 b 1 c
