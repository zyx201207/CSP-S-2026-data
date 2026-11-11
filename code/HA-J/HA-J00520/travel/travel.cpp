#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
int c1,s1,c2,s2;
char S1,S2;//车票对应的座位相邻和车厢有关系吗？ 
int main(){
	freopen("travel.in" ,"r",stdin );
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&c1,&s1,&S1,&c2,&s2,&S2);
//	cout<<c1<<' '<<s1<<S1<<' '<<c2<<' '<<s2<<S2<<endl;
	if(c1!=c2)
		printf("0000");
	else{
		putchar('1');
		if(s1!=s2)
			printf("000");
		else{
			putchar('1');
			if(('D'<=S1&&S1<='F'&&'D'<=S2&&S2=='F')||('A'<=S1&&S1<='C'&&'A'<=S2&&S2<='C')){
				putchar('1');
				if(S1+1==S2||S2+1==S1)
					putchar('1');
				else
					putchar('0');
			}
			else{
				printf("00");
			}
		}
	}
	return 0;
} 
