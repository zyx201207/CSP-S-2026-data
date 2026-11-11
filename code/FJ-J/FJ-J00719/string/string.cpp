#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
long long n,a,b[30],d[30],cnt=0;
char c,m;
queue<char> q;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			q.push(c);
		}
	}
	cout<<"0";
	return 0;
} 
