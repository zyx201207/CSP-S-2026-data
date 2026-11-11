//GZ-J00658 陈泓澍 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000000005];
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	int num=0,st=0;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		char m;
		cin>>m;
		for(long long i=num+1;i<=num+x;i++){
			a[i]=m;
		}
		num+=x;
	}
	if(num%2==1){	
		for(int i=1;i<=num/2+1;i++){
			if(a[num-i+1]==a[i]) st++;
		}
		if(st==(num/2+1)){
			cout<<0;
			return 0;
		}
		else cout<<(num/2+1)-st;return 0;
	}
	else{
		for(int i=1;i<=num/2;i++){
			if(a[num-i+1]==a[i]) st++;
		}
		if(st==(num/2)){
			cout<<0;
			return 0;
		}
		else cout<<(num/2+1)-st;return 0;
	}
	return 0;
}
