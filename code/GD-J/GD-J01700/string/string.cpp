#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const long long N=2e14;
char ch[N];
int n;
long long cnt=0,pos=0,mx=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		int num;char tmp;
		cin>>num>>tmp;
		while(num--)ch[pos++]=tmp;
	}
	for(int i=0,j=pos-1;i<j;i++,j--){
		if(ch[i]!=ch[j])cnt++;
    }
	cout<<cnt;
	return 0;
} 
