#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	string bl;
	char b;
	long long n,a,now2=0;
	cin>>n;
	int now=1,z=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		now2+=a;
		for(int i=now;i<now+a;i++){
			bl[i]=b;
		}
	}
	int nowl=now2;
	for(int i=1;i<=now;i++){
		if(int(bl[i])==int(bl[now])&&nowl>i){
			z++;
		}
		nowl=nowl-1;
	}
	cout<<z;
	return 0;
}
