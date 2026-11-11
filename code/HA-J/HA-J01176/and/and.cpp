#include<bits/stdc++.h>
using namespace std;
long long a[500009];
string s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b;
	cin>>a>>b;
	int s=-1;
	int m;
	for(int i=0;i<a;i++){
		cin>>m;
		if(m>s){
			s=m;
		}
	}
	cout<<s;
	return 0;
}
