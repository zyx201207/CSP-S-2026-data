//GZ-J00016 遵义市第十九中学 王明杰
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d;
	long long int a,c,ta=0,tb=0,tc=0,td=0;
	cin>>a>>b>>c>>d;
	int e=b[2]-'0',f=d[2]-'0',n=(b[1]-'0')+(b[0]-'0')*10,m=(d[1]-'0')+(d[0]-'0')*10;
	if(e==22) e--;
	if(f==22) f--;
	if(a==c){
		ta++;
		if(n==m){
			tb++;
			if((e<=19&&f<=19)||(e>=20&&f>=20)){
				tc++;
				if(e-f==1||e-f==-1){
					td++;
					cout<<ta<<tb<<tc<<td;
				}
				else cout<<ta<<tb<<tc<<td;
			}
			else cout<<ta<<tb<<tc<<td;
		}
		else cout<<ta<<tb<<tc<<td;
	}
	else cout<<ta<<tb<<tc<<td;
	//cout<<ta<<tb<<tc<<td<<" "<<e<<" "<<f;
	return 0;
}

	//int e=a[2]-'0';
	//&& == ||= !=
	//cout<<ta<<tb<<tc<<td<<" "<<e<<" "<<f;
