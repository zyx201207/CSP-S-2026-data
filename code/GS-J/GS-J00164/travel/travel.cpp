#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2>>n;
	for(int i=1;i<=c1*c2;i++)
	{
		if(c1==c2&&s1==s2)
		{
			cout<<"1111";
		}else if(c1==c2&&s1!=s2){
			cout<<"1110";
		}else if(c1!=c2&&s1==s2){
			cout<<"1101";
		}else if(c1!=c2&&s1!=s2){
			cout<<"0000";
		}else{
			cout<<"1000";
		}
	}
	return 0;
	
}
