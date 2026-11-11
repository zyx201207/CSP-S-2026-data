#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+5;
int n;
int num[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>num[i];
	cout<<num[n];
	return 0;
}
