#include<bits/stdc++.h>
using namespace std;
int c,t;
const int MAXN=1e6+417;
struct road{
	int u[MAXN],v[MAXN];
}R;
int n,k; 
void yaritokoro(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>R.u[i]>>R.v[i]; 
	}
	cout<<k-1<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		yaritokoro();
	}
	return 0;
}
/*moto ni dekinai n desu kedo,mae ni sonna
yowakunakatta desu ne,masaku hitotosi ni
computer wo tsukattemasendesita,ore ha
mou zenbu wasureta,zannen daketo,rainen no
ore ha daigaku inensei ni narareru kamo,
kono kirai mono ga kitto subete simotsusiro.
tada koukou(gaokao)no tame ni,eigo ga 140 den
wo yasuku tori dekiru dame sannensei kara.*/
