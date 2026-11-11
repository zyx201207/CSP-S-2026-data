#include<bits/stdc++.h>
using namespace std;
deque<char> a,d;
char b;
long long c,n,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>c>>b;
		for(int j=0;j<c;j++){
			a.push_back(b);
		}
		for(int j=c;j>0;j--){
			d.push_back(b);
			m++;
		}
	}
	cout<<0;
	return 0;
}
