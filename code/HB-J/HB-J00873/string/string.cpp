#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10,M=1e5+10;
int n,a[N],k,cnt;
char c[N],s[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			k++;
			s[k]=c[i];
		}
	}int left=1,ri=k;
	while(left<=ri){
		if(s[left]!=s[ri]) cnt++;
		left++;
		ri--;
	}cout<<cnt;
	return 0;
}
