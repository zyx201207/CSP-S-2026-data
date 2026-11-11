#include<bits/stdc++.h>
using namespace std;
set<int> s;
long long n,a[100005];
char c[1000005];
bool check=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s.insert(c[i]);
	}
	int m=s.size();
	if(m==1){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	return 0;
}

