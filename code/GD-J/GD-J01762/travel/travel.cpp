#include<bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;
int ans[4]={0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans[0]=1;
	else ans[0]=0;
	
	int a=(s1[0]-'0')*10+(s1[1]-'0');
	int b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b&&ans[0]==1) ans[1]=1;
	else ans[1]=0;
	
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&ans[1]==1) ans[2]=1;
	else ans[2]=0;
	
	if(abs(s1[2]-s2[2])==1&&ans[2]==1) ans[3]=1;
	else ans[3]=0;
	
	cout << ans[0] << ans[1] << ans[2] << ans[3] << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
