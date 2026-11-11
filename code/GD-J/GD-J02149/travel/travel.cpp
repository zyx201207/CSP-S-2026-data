#include <iostream>
using namespace std;
string n,c;
int ac,ap,aw;
int bc,bp,bw;
//	freopen("travel.in","rb",stdin);
//	freopen("travel.out","wb",stdin);
int main(){
	freopen("travel.in","rb",stdin);
	freopen("travel.out","wb",stdout);
	cin>>n>>c;
	ac=(n[0]-'0')*10+(n[1]-'0');
	ap=(c[0]-'0')*10+(c[1]-'0');
	aw=c[2]-'A';
	cin>>n>>c;
	bc=(n[0]-'0')*10+(n[1]-'0');
	bp=(c[0]-'0')*10+(c[1]-'0');
	bw=c[2]-'A';
	bool f1=(ac==bc);
	bool f2=f1&&(ap==bp);
	bool f3=f2&&((aw>2)==(bw>2));
	cout<<f1<<f2<<f3;
	if(f3&&aw<bw)swap(aw,bw);
	cout<<(f3&&(aw-bw<=1));
	return 0;
}
