//GZ-J00652 ует╙Ог 
#include<bits/stdc++.h>
using namespace std;
long long jg[5];
char cr[3],sr[4],cx[3],sx[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>cr[1]>>cr[2]>>sr[1]>>sr[2]>>sr[3]>>cx[1]>>cx[2]>>sx[1]>>sx[2]>>sx[3];
	if(cr[1]==cx[1]&&cr[2]==cx[2]) jg[1]=1;
	if(jg[1]==1&&(sr[1]==sx[1]&&sr[2]==sx[2])) jg[2]=1;
	if(jg[2]==1&&((sr[3]<='C'&&sx[3]<='C')||(sr[3]>='D'&&sx[3]>='D'))) jg[3]=1;
	if(jg[3]==1&&(sr[3]-1==sx[3]||sr[3]+1==sx[3])) jg[4]=1;
	cout<<jg[1]<<" "<<jg[2]<<" "<<jg[3]<<" "<<jg[4]<<endl;
	return 0;
}

