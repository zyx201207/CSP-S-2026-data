#include "bits/stdc++.h"
using namespace std;
#define LL long long
const int N=1e5+5;
char c1,c2;
int a1,b1,a2,b2;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
//	printf ("%d %d %c\n%d %d %c\n",a1,a2,c1,b1,b2,c2);
	if (a1==a2){
		cout<<"1";
		if (b1==b2){
			cout<<"1";
			if ('C'>=c1 && 'C'>=c2){
				cout<<"1";
				if (c1-c2==1 || c1-c2==-1) cout<<"1";
				else cout<<"0";
			}
			else 
				if ('D'<=c1 && 'D'<=c2){
					cout<<"11";
				}
				else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
}
