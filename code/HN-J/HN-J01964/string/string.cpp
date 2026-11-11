#include<bits/stdc++.h>
using namespace std;
#define L long long
L n,q;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	L cnt=0;
	while(n--){
		cin>>q>>c;
		for(int i=cnt;i<q+cnt;i++){
			s[i]=c;
		}
		cnt+=q;
	}
	L sum=0;
	for(L i=0;i<cnt/2;i++){
		if(s[i]==s[cnt-i-1]){
			continue;
		}else{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
