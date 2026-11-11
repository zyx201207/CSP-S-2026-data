#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
string a,b,c,d;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d; 
	if(a==c){// 车厢相同 
		ans[0]=1;
		if(b[0]==d[0]&&b[1]==d[1]){// 列相同 
			ans[1]=1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){//同一侧 
				ans[2]=ans[3]=1;
				if(b[2]=='A'&&d[2]=='C')ans[3]=0;//只有 AC 对不相邻 
				else if(b[2]=='C'&&d[2]=='A')ans[3]=0;
			}
		}
	}
	for(int i=0;i<4;++i)printf("%d",ans[i]);
	return 0;
}//不是，我在最后半个小时才看见右边没有 E，这也太坑了。 
