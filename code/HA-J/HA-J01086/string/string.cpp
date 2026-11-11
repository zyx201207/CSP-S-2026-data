#include<iostream>
using namespace std;
const int N=2e5+10;
int n;
int num[200010];
char character[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>character[i];
	}
	return 0;
} 
