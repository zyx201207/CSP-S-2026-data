#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int arr[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		arr[0]=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			arr[1]=1;
			if((s1[2]=='C' || s1[2]=='A' || s1[2]=='B') && (s2[2]=='C' || s2[2]=='A' || s2[2]=='B')){
				arr[2]=1;
				if((s1[2]=='A' || s1[2]=='B') && (s2[2]=='B' || s2[2]=='A'))arr[3]=1;
				else if((s1[2]=='C' || s1[2]=='B') && (s2[2]=='B' || s2[2]=='C'))arr[3]=1;
				else arr[3]=0;
			}
			else if((s1[2]=='F' || s1[2]=='D') && (s2[2]=='D' || s2[2]=='F'))arr[2]=1,arr[3]=1;
			else arr[2]=0,arr[3]=0;
		}
	}
	else{cout<<"0000";fclose(stdin);fclose(stdout);return 0;}
	for(int i=0;i<4;i++)cout<<arr[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
