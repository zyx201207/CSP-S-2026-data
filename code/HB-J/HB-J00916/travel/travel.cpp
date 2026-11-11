#include<bits/stdc++.h>
using namespace std;
char c[4],d[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    cin>>a;
    for(int i=0;i<3;i++)
        cin>>c[i];
    cin>>b;
    for(int i=0;i<3;i++)
        cin>>d[i];
    if(a==b)
    {
    	cout<<"1";
    }
    else
    	cout<<"0";
    if(c[1]==d[1]&&c[2]==d[2])
        cout<<"1";
    else
    	 cout<<"0";     
    if((c[3]=='A'&&d[3]=='B')||(c[3]=='C'&&d[3]=='D')||(c[3]=='C'&&d[3]=='F')||(c[3]=='D'&&d[3]=='C')||(c[3]=='D'&&d[3]=='F')||(c[3]=='F'&&d[3]=='D')||(c[3]=='F'&&d[3]=='C'))
    	 cout<<"1";
    else
    	cout<<"0";
    if((c[3]=='A'&&d[3]=='B')||(c[3]=='C'&&d[3]=='D')||(c[3]=='D'&&d[3]=='F'))
    	 cout<<"1"; 
    else
        cout<<"0";
    return 0;
}
