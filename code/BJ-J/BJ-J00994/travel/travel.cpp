#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int R1,X1,R2,X2;
	char R3,X3;
	cin>>R1>>R2>>R3;
	cin>>X1>>X2>>X3;
	cout<<(R1==X1);
	cout<<(R1==X1 and R2==X2);
	bool sameside=((R1==X1) and (R2==X2) and (((R3=='A' or R3=='B' or R3=='C') and (X3=='A' or X3=='B' or X3=='C')) or ((R3=='D' or R3=='F') and (X3=='D' or X3=='F'))));
	cout<<sameside;
	cout<<(sameside and (R3+1==X3 or R3-1==X3));
	return 0;
}
