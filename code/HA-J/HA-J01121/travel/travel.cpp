#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
int sum1,sum2,z,zz;
int main()
{
	freopen("trawel.in","r",stdin);
	freopen("trawel.out","w",stdout);	
    cin>>s1>>ss1>>s2>>ss2;
    if(s1[0]=='1') sum1=1;
    if(s1[1]=='1') sum1=sum1*10+1;
    else if(s1[1]=='2') sum1=sum1*10+2;
    else if(s1[1]=='3') sum1=sum1*10+3;
    else if(s1[1]=='4') sum1=sum1*10+4;
    else if(s1[1]=='5') sum1=sum1*10+5;
    else if(s1[1]=='6') sum1=sum1*10+6;
    else if(s1[1]=='7') sum1=sum1*10+7;
    else if(s1[1]=='8') sum1=sum1*10+8;
    else if(s1[1]=='9') sum1=sum1*10+9;
    if(s2[0]=='1') sum2=1;
    if(s2[1]=='1') sum2=sum2*10+1;
    else if(s2[1]=='2') sum2=sum2*10+2;
    else if(s2[1]=='3') sum2=sum2*10+3;
    else if(s2[1]=='4') sum2=sum2*10+4;
    else if(s2[1]=='5') sum2=sum2*10+5;
    else if(s2[1]=='6') sum2=sum2*10+6;
    else if(s2[1]=='7') sum2=sum2*10+7;
    else if(s2[1]=='8') sum2=sum2*10+8;
    else if(s2[1]=='9') sum2=sum2*10+9;
    
    if(sum1==sum2) cout<<1;
    else cout<<0;
    
    if(ss1[0]=='1') z=1;
    if(ss1[1]=='1') z=z*10+1;
    else if(ss1[1]=='2') z=z*10+2;
    else if(ss1[1]=='3') z=z*10+3;
    else if(ss1[1]=='4') z=z*10+4;
    else if(ss1[1]=='5') z=z*10+5;
    else if(ss1[1]=='6') z=z*10+6;
    else if(ss1[1]=='7') z=z*10+7;
    else if(ss1[1]=='8') z=z*10+8;
    else if(s1[1]=='9') z=z*10+9;
    if(ss2[0]=='1') zz=1;
    if(ss2[1]=='1') zz=zz*10+1;
    else if(ss2[1]=='2') zz=zz*10+2;
    else if(ss2[1]=='3') zz=zz*10+3;
    else if(ss2[1]=='4') zz=zz*10+4;
    else if(ss2[1]=='5') zz=zz*10+5;
    else if(ss2[1]=='6') zz=zz*10+6;
    else if(ss2[1]=='7') zz=zz*10+7;
    else if(ss2[1]=='8') zz=zz*10+8;
    else if(ss2[1]=='9') zz=zz*10+9;
    char x=ss1[2],y=ss2[2];
    if(sum1==sum2 && z==zz) cout<<1;
    else cout<<0;
    if(sum1==sum2 && z==zz && ((x=='F' && y=='D') || (x=='D' && y=='F') || (x=='A' && (y=='B' || y=='C')) || (x=='B' && (y=='A' || y=='C')) || (x=='C' && (y=='A' || y=='B'))))
    {
    	cout<<1;
    }
    else cout<<0; 
    if(sum1==sum2 && z==zz && ((x=='A' && y=='B') || (x=='B' && y=='C') || (x=='F' && y=='D') || (x=='B' && y=='A') || (x=='C' && y=='B') || (x=='D' && y=='F')))
    {
    	cout<<1;
    }
    else cout<<0; 
	return 0;
}



