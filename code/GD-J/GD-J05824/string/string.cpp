#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,cnt=0,sum=0;
	char c;
	string d[10000];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>c;
		for(int j=cnt;j<cnt+b;i++){
			d[i]=c;
		}
		cnt+=b;
	}
	for(int i=0;i<cnt/2;i++){
		if(d[i]==d[cnt-1-i]) {
			sum++;
		}
		else{
			cout<<2;
		}
	}
	if(sum==cnt/2){
		cout<<0;
	}
	return 0;	
}

