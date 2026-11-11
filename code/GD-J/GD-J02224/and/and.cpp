#include<bits/stdc++.h>
using namespace std;
int m,n,ar[200005] = {},pos = 0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		if(pos<m||l>ar[m]){
			pos++;
			int p=m;
			while(p>0){
				if(l<ar[p])break;
				p--;
			}p++;
			for(int i=m;i>=p;i--)ar[i+1] = ar[i];
			ar[p] = l;
		}
	}
	int ans = ar[1];
	for(int i=2;i<=m;i++)ans = ans&ar[i];
	cout<<ans;
	return 0;
}

