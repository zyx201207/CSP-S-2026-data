#include <bits/stdc++.h>
using namespace std;
string seat[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    bool same=1;
    bool cs=1;
    
    
    for (int i=0;i<4;i++)
    cin>>seat[i];

    char l1=seat[1][2];
    char l2=seat[3][2];
    int lr1=0;
    int lr2=0;

    if (l1=='D'||l1=='F')
    lr1=1;
    if (l2=='D'||l2=='F')
    lr2=1;
    
    if (seat[0]==seat[2])
    cout<<1;
    else {
    	cout<<0;cs=0;}
    	
    if (seat[1][0]==seat[3][0] && seat[1][1]==seat[3][1] &&cs)
    cout<<1;
    else {cout<<0;same=0;}
    
    if (same && (lr1==lr2))
    cout<<1;
    else cout<<0;
    
    if (same){
	
    if (l1=='A')
    cout<<(l2=='B');
    else if(l1=='B')
    cout<<(l2=='A'||l2=='C');
    else if(l1=='C')
    cout<<(l2=='B');
    else if(l1=='D')
    cout<<(l2=='F');
    else cout<<(l2=='D');
	}
	else cout<<0;

    return 0;
}
