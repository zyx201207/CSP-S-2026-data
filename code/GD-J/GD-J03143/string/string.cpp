#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2*1e5+10;
const int M=1e9+10;
LL n,ans,sum;
char s[M];
struct abc{
	LL num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
		while(a[i].num--){
			s[j]=a[i].c;
			j++;
		}
	}
	j--;
	for(int i=0;i<=j;i++){
		if(i>=j-i) break;
		if(s[i]!=s[j-i]) ans++;
	}
	cout<<ans;
	return 0;
}
