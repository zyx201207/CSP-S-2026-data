#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii = pair<int,int> ;
struct str{
	int a;
	char b;
}a[200100];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		cin>>a[i].b;
		m+=a[i].a;
	}
	int s=0,z2=a[n].a,ans=0;
	for(int i=1,j=n;i<=n;i++){
		if(s>=m/2)break;
		int z1=a[i].a;
		while(i<j&&z2<z1){
			z1-=z2;
			if(a[i].b!=a[j].b)ans+=z2;
			j--;
			z2=a[j].a;
		}
		if(a[i].b!=a[j].b)ans+=min(z1,z2);
		z2-=z1;
		s+=a[i].a;
	}
	cout<<ans; 
	return 0;
}
/*
4
1 a
4 b
1 c
1 d
abbbbcd

*/
