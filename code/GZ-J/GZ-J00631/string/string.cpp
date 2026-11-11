//GZ-J00631 六盘水市第二十四中学 廖国吉
#include<bits/stdc++.h>
int a,sum,tou=1,wei,num=0,n;
char b,c[1000000005];
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		for(int i=1;i<=a+sum;i++) c[i+sum]=b;
		sum+=a;
	}
	wei=sum;
	for(int i=1;i<=sum;i++){
		if(wei<=tou){
			cout<<num;
			return 0;
		}
		if(c[tou]!=c[wei]) num++;
		tou++;
		wei--;
	}
	return 0;
}

