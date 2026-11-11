#include<bits/stdc++.h>
using namespace std;
int a[25], b[25], c[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1, c2;
	char s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag1=0, flag2=0, flag3=0, flag4=0;
	int n1, n2, m1, m2;
	while(s1){
		int m1=getchar();
		s1=s1-'0';
		m1=m1-'0';
		for(int i=01; i<=18;i++){
			if(a[i]*100+m1==s1) a[i]=n1;
		}
	}
	while(s2){
		int m2=getchar();
		s2=s2-'0';
		m2=m2-'0';
		for(int i=01; i<=18;i++){
			if(b[i]*100+m2==s2) b[i]=n2;
		}
	}
	if(c1==c2) flag1++;
	if(n1==n2) flag2++;
	for(int i='A'; i<='F';i++){
		cin >> c[i];
		if(n1==n2 && m1<=c[3] && m2<=c[3]) flag3++;
		else if(n1==n2 && m1>=c[4] && m1<=c[5] && m2>=c[4] && m2<=c[5]) flag3++;
	}
	if(flag1==1 && flag2==1 && flag3==1 && m1+1==m2) flag4++;
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
