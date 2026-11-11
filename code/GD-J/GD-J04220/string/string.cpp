#include <bits/stdc++.h>
using namespace std;
string str_basic;
char ch;
long long  cnt,n,m,lenth;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	str_basic="";
	for(int i=1;i<=n;i++){
		cin>>m>>ch;
		lenth+=m;
		for(int j=1;j<=m;j++){
			str_basic+=ch;
		}
	}
	if(lenth%2==0){
		for(int i=0;i<=(str_basic.size())/2-1;i++){
			if(str_basic[i]!=str_basic[str_basic.size()-i-1]) cnt++;
		}
	}else{
		for(int i=0;i<=(str_basic.size()-1)/2;i++){
			if(str_basic[i]!=str_basic[str_basic.size()-i-1]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
