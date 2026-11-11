#include<bits/stdc++.h>
using namespace std;

int n,t;
char c;
long long cnt;
string str="1";//zongchuan
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&t,&c);
		
		for(int j=1;j<=t;j++){
		str+=c;
		}
		
	}
	
	for(int i=1;i<=(str.size()-1)/2;i++){
		
		if(str[i] != str[str.size()-i]){
			cnt++;//¼Ç´í+1 
		}
	}
	printf("%lld",cnt);
	return 0;
}

