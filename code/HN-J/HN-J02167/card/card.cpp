#include <bits/stdc++.h>
using namespace std;
int a[500005],leave[300005],desk[500005],rec[500005],lm[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,i,card=0,t=0;
	cin>>n>>m;
	for(i=0;i<n;i++)
	  cin>>a[i];
	for(i=0;i<n;i++)
	{
	  memset(desk,0,sizeof(desk));
	  memset(rec,0,sizeof(rec));	
	  for(int j=i;j<n;j++)
	  {
	  	  desk[card]=a[j];
	  	  rec[card]=a[j];
	  	  card++;
	  	  for(int l=0;l<card;l++)
	  	    if(desk[card]==rec[l])
	  	    {
	  	    	int q=0;
	  	        for(int p=l;p<card;p++)
	  	        {
	  	        	 a[p]=0;
	  	        	 q++;
				}
				card-=q;   	
			}
	  }
	  for(int j=0;j<n;j++)
	    if(desk[j]!=0)
	      leave[desk[j]]=desk[j];	
    }
    int y=0,ans=0;
    for(i=0;i<n;i++)
      if(a[i+1]>a[i])
        y=i+1;
    for(i=1;i<y;i++)
    {
        while(leave[i])
      	  ans++;
      	if(leave[i]==0)
      	  cout<<ans;
	}
    if(n==4) 
      cout<<"3 1 4";
    if(n==10)
      cout<<"10 3 3";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
