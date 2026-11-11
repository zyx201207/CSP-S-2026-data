#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5]={0};
    int list[n+5]={0};
    int ans[n+5]={0};
    int bj=0;
    bool B=0;

    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for (int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
        	B=0; 
            for (int k=0;k<n;k++)
            {
                if (a[j]==list[k])
                {
                    bj=k;
                    B=1;
                    break;
                }    
       		}
       	if (B)
        {
            for (int o=bj;o<n;o++)
            list[o]=0;
            list[bj]=a[j];
		}
		else
		list[j]=a[j];	
       	
        
    	}
    	
        for(int p=0;p<n;p++)
       	ans[list[p]]++;
        for(int q=0;q<n;q++)
        list[q]=0;
	}

    for (int i=1;i<=m;i++)
    {
    	cout<<ans[i]<<' ';
	}

    return 0;
}
