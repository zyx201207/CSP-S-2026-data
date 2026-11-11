#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Node{
	long long num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long L=0,cnt=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		for(long long t=0;t<a[i].num;t++)s+=a[i].c;
		L+=a[i].num;
	}
	L--;
	for(long long i=0;i<(1+L)>>1;i++){
		if(s[i]!=s[i+L-1]){
//			cout<<i<<" "<<i+L-1<<"\n\n";
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
