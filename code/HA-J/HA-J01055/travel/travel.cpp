#include<bits/stdc++.h>
using namespace std;
struct trian
{
	string c;
	string s;
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	trian a[5];
	for(int i=1;i<=2;i++){
		cin>>a[i].c>>a[i].s;
	}
	if(a[1].c==a[2].c)
	{
		cout<<1;
		if(a[1].s[0]==a[2].s[0]&&a[1].s[1]==a[2].s[1]){
			cout<<1;
			if(a[1].s[2]+a[2].s[2]=='D'+'F'){
				cout<<1;
				cout<<1;
			}
			else if((a[1].s[2]=='A'||a[1].s[2]=='B'||a[1].s[2]=='C')&&(a[2].s[2]=='A'||a[2].s[2]=='B'||a[2].s[2]=='C')){
				cout<<1;
				if(a[1].s[2]+a[2].s[2]=='A'+'B'||a[1].s[2]+a[2].s[2]=='B'+'C'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
				cout<<0;
			}
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
