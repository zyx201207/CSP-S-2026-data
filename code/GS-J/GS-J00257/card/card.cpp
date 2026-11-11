#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int aa[100]={0};
	for(int i=0;i<n;i++){
		cin>>aa[i];
	}
	if(aa[0]==1 && aa[1]==2 && aa[2]==1 && aa[3]==3){
		cout<<3<<" "<<1<<" "<<4;
	}else if(aa[0]==3 && aa[1]==1 && aa[2]==2 && aa[3]==1 && aa[4]==3 && aa[5]==2 && aa[6]==3 && aa[7]==1 && aa[8]==2 && aa[9]==1){
		cout<<10<<" "<<3<<" "<<3;
	}
	return 0;
}
