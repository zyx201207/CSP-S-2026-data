#include<bits/stdc++.h>
using namespace std;
int n;
long long a,num,d;
char c;
string ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=0;j<a;j++){
			ans[++num]=c;
		}
	}for(int i=1;i<=num/2;i++){
		if(ans[i]!=ans[num-i+1]){
			++d;
		} 
	}
	cout<<d;
	return 0;
}
