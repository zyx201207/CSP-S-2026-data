#include<bits/stdc++.h>
using namespace std;    
long long n,m,a[200005],maxn=-2e9;
bool b[200005];
void dsf(int x,int l,int num)
{
	if(num==m)
	{
	    if(x>maxn) maxn=x;
		return ;
	}
	if(b[l]==0)
	{
		b[l]=1;
		int zhy=x,blc=a[l],j1[100],j2[100],j3[100],i=1,j=1,h;
		while(zhy!=0){
			j1[i]=zhy%2;
			zhy/=2;
			i++;
		}
		while(blc!=0){
			j2[j]=blc%2;
			blc/=2;
			j++;
		}	 
		if(i>j)  h=j-1;
		else  h=i-1;
	
		for(int z=2;z<=h;z++) 
		{	
			if(j1[z]==1&&j2[z]==1) j3[z]=1;
			else j3[z]=0;
		   
		}
		x=0;
		for(int z=h;z>=2;z--) x=x*2+j3[i];
		num++;
		for(int y=1;y<=n;y++) dsf(x,y,num);
		num--;
		b[l]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dsf(0,0,0);
    cout<<maxn;
	return 0;
}



