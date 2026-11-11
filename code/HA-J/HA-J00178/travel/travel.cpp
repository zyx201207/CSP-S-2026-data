#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char b2,d2;
int a1,c1,b1,d1;
map<int,char>mp;
int p[105];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int len2=b.size();
	int len4=d.size();
	for(int i=0;i<2;i++){
		int x=a[i]-'0';
		a1=a1*10+x;
		int y=c[i]-'0';
		c1=c1*10+y;
	}
	if(a1==c1){
		p[0]=1;
		for(int i=0;i<3;i++){
		    if(b[i]>'0'&&b[i]<='9'){
			    int x=b[i]-'0';
			    b1=b1*10+x;
		    }
		    else if(b[i]>='A'&&b[i]<='F')b2=b[i];
		    if(d[i]>'0'&&d[i]<='9'){
			    int x=d[i]-'0';
				d1=d1*10+x;
			}
			else if(d[i]>='A'&&d[i]<='F')d2=d[i];
		}
		if(b1==d1){
			p[1]=1;
			if(b2>='A'&&b2<='C'||d2>='D'&&d2<='F'){
				p[2]=1;
				if(b2=='C'&&d2=='D'||b2=='D'&&d2=='C')p[3]=0;
				else {
					int x=b2-'A';
					int y=d2-'A';
					if(abs(x-y)==1)p[3]=1;
				}
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<p[i];
	}
	return 0;
}
