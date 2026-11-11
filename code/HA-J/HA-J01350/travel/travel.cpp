#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool ff=(c1==c2);
	cout<<ff;
	bool f=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			f=0;
			break;
		}
	}
	cout<<(f&&ff);
	int a=s1[2]-'A'+1;
	int b=s2[2]-'A'+1;
	cout<<(((3>=a&&1<=a&&3>=b&&1<=b)||(5>=a&&4<=a&&5>=b&&4<=b))&&f&&ff);
	if(a>b)swap(a,b);
	cout<<(((a==1&&b==2)||(a==2&&b==3)||(a==4&&b==5))&&f&&ff);
	return 0;
}

