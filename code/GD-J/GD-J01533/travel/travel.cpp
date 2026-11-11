#include <bits/stdc++.h>
#define let long long
#define str string
#define rt return
using namespace std;

str a,b,c,d;
let x,y,z,w,n,m,
	mp[10];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(let i = 0;i<a.size();i++){
		x+=int(a[i]-'0');
		x*=10;
	}
	for(let i = 0;i<c.size();i++){
		z+=int(c[i]-'0');
		z*=10;
	}
	for(let i = 0;i<b.size()-1;i++){
		y+=int(b[i]-'0');
		y*=10;
	}
	for(let i = 0;i<d.size()-1;i++){
		w+=int(d[i]-'0');
		w*=10;
	}
	n = int(b[2]-'A')+1,m = int(d[2]-'A')+1;
	if(x == z)mp[1] = 1;
	if(mp[1]&&y==w) mp[2] = 1;
	if((mp[2])&&((1<=n&&n<=3)&&((1<=m&&m<=3))||((4<=n&&n<=5)&&(4<=m&&m<=5)))) mp[3] = 1;
	if(mp[3]){
		if(n+1==m||n-1==m) mp[4] = 1;
	}
	for(let i = 1;i<=4;i++) cout<<mp[i];
	//cout<<"\n"<<n<<" "<<m;
	rt 0;
	
}
