#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long L,res;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i]>>c[i],L+=a[i];
	int i=1,j=n;
	while(i<j){
		int solve=min(a[i],a[j]);
		if(c[i]!=c[j]){
			res+=solve;
		}
		a[i]-=solve;a[j]-=solve;
		if(a[i]==0)	i++;
		if(a[j]==0)	j--;
	}cout<<res<<endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
