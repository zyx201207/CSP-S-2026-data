#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m,a[9178666];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//¹öÄ¾¹öÄ¾ 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n<<m<<a[1];
	return 0;
}
