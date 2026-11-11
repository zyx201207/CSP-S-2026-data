#include <bits/stdc++.h>

using namespace std;
int a1,a2,b1,b2,a[5];
char a3,b3;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1;
	scanf("%2d%c",&a2,&a3);
	cin>>b1;
	scanf("%2d%c",&b2,&b3);
	if(a1==b1){
		a[1]=1;
		if(a2==b2){
			a[2]=1;
			if(((a3=='A'||a3=='B'||a3=='C')&&(b3=='A'||b3=='B'||b3=='C'))
			||((a3=='D'||a3=='F')&&(b3=='F'||b3=='D'))){
				a[3]=1;
				if(a3=='A'&&b3=='B') a[4]=1;
				else if(a3=='B'&&(b3=='A'||b3=='C')) a[4]=1;
				else if(a3=='C'&&b3=='B') a[4]=1;
				else if(a3=='D'&&b3=='F') a[4]=1;
				else if(a3=='F'&&b3=='D') a[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<a[i];
	return 0;
}
