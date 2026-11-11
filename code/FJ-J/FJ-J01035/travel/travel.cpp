#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int ac,ap,bc,bp;
	char al,bl;
	cin>>ac>>ap>>al>>bc>>bp>>bl;
	if(ac==bc){
		a[1]=1;
		if(ap==bp){
			a[2]=1;
			int ak=al-'A'+1,bk=bl-'A'+1;
			if(((ak<=3)^(bk<=3))==0)a[3]=1;
			if(a[3]==1&&abs(ak-bk)==1)a[4]=1;
		}
	}
	for(int i=1;i<=4;i++)cout<<a[i];
	return 0;
}
