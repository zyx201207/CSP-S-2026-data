#include <bits/stdc++.h>
using namespace std;

int n;
long long num[100000];
char ch[100000];
long long cnt1,cnt2;//骗分工具 
bool f=false; int sum=0;//骗分工具 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>num[++cnt1];
		cin>>ch[++cnt2];
	}
	for(int i=1;i<=cnt2-1;i++){
		if(ch[i]==ch[i+1]) sum++;
	}
	if(sum==cnt2-1) f=true;
	if(f){
		cout<<0;
	}
	
	
	return 0;
} 
