//遵义市滨湖中学 GZ-S00479  胡泽雨 
#include <bits/stdc++.h>
using namespace std;

long long n;
string g;

int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
long long a=0,c=0,num=0;
	cin>>n;
	char s;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		for(int j=c;j<=a+c;j++){
			g+=s;
		}c+=a;
	}
	for(int i=1;i<=(c+1)/2;i++){
		if(g[i]!=g[c+1-i]){
			num++;
		}
	}if(num==0){
		cout<<0	;
		return 0;
	}
	cout<<num;
fclose(stdin);
	fclose(stdout);
}

