#include<bits/stdc++.h>
#define ll long long 
#define db double
using namespace std;
string c_1,s_1,c_2,s_2;
bool qa,qb,qc,qd=true;
int l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	int paia=0,paib=0;
	for(int i=0;i<=1;i++){
		if(i==0)paia+=int((s_1[i]-'0'))*10,paib+=int((s_2[i]-'0'))*10;
		else paia+=int((s_1[i]-'0')),paib+=int((s_2[i]-'0'));
	}
	char haoa=s_1[2],haob=s_2[2];
	if(haoa=='A'||haoa=='B'||haoa=='C') l++;
	else r++;
	if(haob=='A'||haob=='B'||haob=='C') l++;
	else r++;
	if(c_1==c_2) qa=true;
	if(qa&&paia==paib) qb=true;
	if(qb&&r==2) qc=true;
	if(qb&&l==2) qc=true;
	if(qc&&haoa=='A'&&haob=='C') qd=false;
	if(qc&&haob=='A'&&haoa=='C') qd=false;
	if(!qc) qd=false;
	if(qa) cout<<1;
	else cout<<0;
	if(qb) cout<<1;
	else cout<<0;
	if(qc) cout<<1;
	else cout<<0;
	if(qd) cout<<1;
	else cout<<0;
	return 0;
}
