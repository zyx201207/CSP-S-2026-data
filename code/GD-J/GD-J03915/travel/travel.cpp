#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1,a2;
	a1=int(s1[0]-'0')*10+int(s1[1]-'0');
	a2=int(s2[0]-'0')*10+int(s2[1]-'0');
	int ans[4]={0,0,0,0};
	if(c1==c2){
		ans[0]=1;
		if(a1==a2){
			ans[1]=1;
			if(s1[2]<'D'&&s2[2]<'D'||s1[2]>'C'&&s2[2]>'C'){
				ans[2]=1;
				if(abs(int(s1[2])-int(s2[2]))==1){
					ans[3]=1;
				}
			}
		}
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
