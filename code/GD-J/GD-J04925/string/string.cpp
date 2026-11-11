#include<iostream>
using namespace std;
string s;
int n,a[100001];
char c[1000001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	char s=c[1];
	for(int i=1;i<=n;i++){
		if(c[i]!=s){
			return 0;
		}
	}
	cout<<0;
}
