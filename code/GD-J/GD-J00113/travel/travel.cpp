#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	int c1,c2;
    string s1,s2;
	freopen("travel.in","r",stdin);cin>>c1>>s1>>c2>>s2;
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);cout.tie(0);
    
    if(c1==c2&&c1>=02&&c1<=15&&c2>=02&&c2<=15)a[1]=1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&a[1]==1)a[2]=1;
    if((s1[2]<='C'&&s2[2]<='C'&&s1[2]>='A'&&s2[2]>='A')||(s1[2]=='D'&&s2[2]=='F')||(s1[3]=='F'&&s2[3]=='D')&&s1!=s2&&s1[2]>='A'&&s2[2]>='A'&&c1==c2)a[3]=1;
    if((s1[2]-'A')==(s2[2]-'A'+1)||(s2[2]-'A')==(s1[2]-'A'+1))a[4]=1;
    for(int i=1;i<=4;i++)cout<<a[i];
}
