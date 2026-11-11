#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2], s1[3], c2[2], s2[3],s3=0000;
	cin>>c1[2]>>s1[3]>>c2[2]>>s2[3];
	if(c1==c2)s3=s3+1000;
	
	if((s1[1]==s2[1])&&(s1[2]==s2[2]))s3+=100;
	if(('A'<=s1[3]&&s1[3]<='C')&&('A'<=s2[3]&&s2[3]<='C'))s3+=10;
	if(('D'<=s1[3]&&s1[3]<='F')&&('D'<=s2[3]&&s2[3]<='F'))s3+=10;
	
	if(s3==1110) s3+=1;
	cout<<s3;
	fclose(stdin);
	fclose(stdout);
}
