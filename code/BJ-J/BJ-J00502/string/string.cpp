
#include <bits/stdc++.h>
//#define int long long
//#define f(i,a,b) f(int i =(a);i<=(b);i++)
using namespace std;
int ans=0;
string kkksc;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	kkksc+=' ';
	char a[200005];
	int m[200005],all=0;
	for(int i=1;i<=n;i++){
		cin >> m[i];
		cin >> a[i];
		for(int i=1;i<=m[i];i++){
			kkksc+=a[i];
		}
		all+=m[i];
	}
	if (all%2==0){
		int ner=all/2;
		for(int i=1;i<=ner;i++){
			if (kkksc[i]!=kkksc[all+ner-1]){
				ans++;
		}
	}
}
cout << ans;
	return 0;
}

