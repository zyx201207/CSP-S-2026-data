#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long m[N],n;
char c[N];
unsigned long long cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s="0";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
	}
	for(int i=1,j=n;i<j;i++,j--){
		if(c[i]!=c[j]&&m[i]==m[j]){
			cnt+=m[j];
		}else if(c[i]!=c[j]&&m[i]!=m[j]){
			if(m[i]<=m[j])swap(m[i],m[j]);
			m[i]-=m[j];
			cnt+=m[j];
			i--;
			continue;
		}else if(c[i]==c[j]&&m[i]!=m[j]){
			if(m[i]<=m[j])swap(m[i],m[j]);
			m[i]-=m[j];
			i--;
		}else {
			continue;
		}
	}
	cout<<cnt;
	return 0;
 } 
