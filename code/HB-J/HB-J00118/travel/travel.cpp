#include <iostream>//AC!
using namespace std;
int rr,xx;
string rc,rz,xc,xz;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc;
	cin>>rz;
	cin>>xc;
	cin>>xz;
	if(rc[0]==xc[0]&&rc[1]==xc[1])
	{
		cout<<1;
		if(rz[0]==xz[0]&&rz[1]==xz[1])
		{
			cout<<1;
			if(rz[2]=='A'||rz[2]=='B'||rz[2]=='C') rr=1;
			else rr=2;
			if(xz[2]=='A'||xz[2]=='B'||xz[2]=='C') xx=1;
			else xx=2;
			if(rr==xx)
			{
				cout<<1;
				if(rz[2]==xz[2]+1||xz[2]==rz[2]+1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
}
