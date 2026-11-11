#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int main(){
	freopen("in.crystal","r",stdin);
	freopen("out.crystal","w",stdout);
	int n,m,cnt;
	cin >> n>>m;
	for(int i=0;i<=n;i++){
		int b;
		cin >> b;
		if(a[i]==a[i+b]) cnt ++;
		else if (a[i]!=a[i+b]){
			if(m >= a[i]-a[i+b]){
				cnt ++;
			}
		}
	}
	cout <<cnt;
	return 0;
}


