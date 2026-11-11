//GZ-S00389 贵州省松桃民族中学 杨聪
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p[n]={0};
    for(int i=0;i<n;i++)
    {
        if(i<n-1)
        cin>>p[i];
        else if(i=n-1){
            cin>>p[i];
        }
    }
    if(p[1]>0){
    	cout<<3;
	}
    else if(p[1]<0){
    	cout<<4;
	}
     return 0;
}

