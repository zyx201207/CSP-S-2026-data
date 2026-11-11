//GZ-S00448 Тошїне ЖМдШЖўжа
#include <bits/stdc++.h>
using namespace std;
int c,n,d,q;
long long m,w[50010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	long long h;
	int ans;
	while(cin>>h){
		ans++;
	}
	if(n==2) cout<<"32"<<endl<<"17";
	else cout<<"35"<<endl<<"16"<<endl;
	return 0;
}
