#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a[10];
int main{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>C2;
	if(c1==c2){
		a[1]=1;
	}
	int flag1=1;
	for(int i=0;i<=2;i++){
		if(s1[i]!=s2[i]){
			flag1=0;
		}
	}
	if(flag1!=0){
		a[2]=1;
	}
	cout<<flag1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
