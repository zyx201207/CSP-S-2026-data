#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+9;
int n,ans;
int a[MAXN],aa[MAXN];
char c[MAXN],cc[MAXN]; 
vector<char>vec1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) vec1.push_back(c[i]);
	}
	//cout<<vec1.size()<<endl;
	for(int i=0;i<(vec1.size()-1)/2;i++){
		//cout<<vec1[i]<<' '<<vec1[vec1.size()-i-1]<<endl;
		if(vec1[i]!=vec1[vec1.size()-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
//3 2 a 2 b 1 c
//2 2 a 3 a