#include<bits/stdc++.h>
using namespace std;
long long sj[500020];long long cz[500020];
int n=0,m=0,ans=0;
int main(){
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout");
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>sj[i];
		if(sj[1]==sj[i]){
			ans++;
		}
	}
	if(ans==n){
	    cout<<ans;
	}
	else if(n==2){
		if(sj[1]>sj[2]&&sj[1]-sj[2]>m)cout<<1;
		else if(sj[2]>sj[1]&&sj[2]-sj[1]>m)cout<<1;
		else cout<<2;
	}
	else{
	ans=0;
    for(int l=1;l<=n-1;l++)
	{
		int i=1;
		for(int r=2;r<=n;r++)
		{
			if(sj[l]<sj[r])cz[i]==sj[r]-sj[l];	
			else if(sj[l]>sj[r])cz[i]==sj[l]-sj[r];	
			else ans++;
			i++;
			for(int l1=1;l1<=n-1;l1++)
		    
			{
		        for(int r1=2;r1<=n;r1++)
			    {
			       if(cz[l1]<cz[r1])cz[r1]==0;
				   else if(cz[l1]>cz[r1])cz[l1]==0;
			    }
		    }
		    for(int i;i<=n;i++)
		    {
			    if(cz[i]!=0)
			    {
			    	ans++;
				    m-=cz[i];
			        if(m-cz[i]<=0){
					    break;
					}
			        break;
			    }
	        }  
	    }
    }
    cout<<ans;
    }
	return 0;
}