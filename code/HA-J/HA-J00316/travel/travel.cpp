#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int RX,RY,XX,XY;
char RS,XS;
int a[5];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>RX>>RY>>RS>>XX>>XY>>XS;
	if(RX==XX){
		a[1]=1;
		if(RY==XY){
			a[2]=1;
			if((RS<='C'&&XS<='C')||(RS>='D'&&XS>='D')){
				a[3]=1;
				if(!(RS=='C'&&XS=='A')&&!(RS=='A'&&XS=='C'))
					a[4]=1;
			}
		}
	}
	for(int i=1;i<=4;++i)
		cout<<a[i];
	return 0;
}
/*
來自中原一群夥伴
   結廬東南山
塵緣難盡莫對寒窗
 龍珠合十在胸膛
        ——我们是中国人 
*/

