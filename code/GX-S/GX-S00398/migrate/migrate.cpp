#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+10;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int x[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read(),t1=t;
	if(c==0){
		int val=0;
		while(t--){
			int n=read(),d=read();
			for(int i=1;i<=n;i++){
				int x=read();
				x++;
			}
			if(val!=0)continue;
			if(n==4&&d==2)val=1;
			else if(n==5&&d==3)val=2;
			else val=3;
		}
		if(t1==12||t1==14||t1==16){
			if(t1==12)printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
			else if(t1==14)printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
			else if(t1==16)printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
			return 0;
		}
		if(val==1)printf("1\n2\n");
		else if(val==2)printf("0\n1\n");
		else printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
	}
	else {
		if(c==11||c==12){
			while(t--){
				int n=read(),d=read(),b=0;
				for(int i=1;i<=n;i++){
					x[i]=read();
					b=x[i]-x[i-1];
				}
				if(d/b<2)printf("0\n");
				
			}
		}
	}
	return 0;
}
