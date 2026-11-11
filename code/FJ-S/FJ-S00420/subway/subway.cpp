#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+417;
struct tikatetsu{
	//  /\?
	int w[MAXN],a[MAXN],t[MAXN]; 
}owari;
int c,n,m,d,q;
//ta si ka ha ya ttr ta roi no mon tai da ke re do mo,i ma kou kou san nen sei no wa ta si mou, ho do ke na i n de su ne,ku so ya rou ;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>owari.w[i];
	cout<<c+n+m+d+q<<endl<<c+n+m;
	return 0;
}
