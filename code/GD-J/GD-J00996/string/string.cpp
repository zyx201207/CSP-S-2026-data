#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200010];//bt=中点 
	char x[200010];
	float bt=0;
	long long sum1=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
		bt+=a[i];
	}
	bt/=2; 
	int w=0,t=0;//t为左侧去除中点数据后的总和 ，w为序号 
	while(t<bt)
	{
		w+=1;
		t+=a[w];
	}
	if (t!=bt){
		if(bt-t+a[w]>t-bt){
			a[w]=a[w]-2*(t-bt);
		}
		if(bt-t+a[w]<t-bt){
			a[w]=a[w]-2*(bt-t+a[w]);
			w-=1;
		}
		else{
			a[w]=0;
			w-=1;
		}
	} 
	int l=1,r=n;
	while(l<=w || r>=w+1){
		if(a[l]>a[r])
		{
			if(x[l]!=x[r])
			{
				sum1+=a[r];
				a[l]-=a[r];
				a[r]=0;
		    }
		    r-=1;
		}
		if(a[r]>a[l])
		{
			if(x[l] != x[r])
			{
			    sum1+=a[l];
			    a[r]-=a[l];
			    a[l]=0;
		    }
		    l+=1;
		}
		else{
			if(x[l]!=x[r])
			{
				sum1+=a[l];
				a[l]=0;
				a[r]=0;
			}
			l+=1;
			r-=1;
		}
	}
	cout<<sum1;
	return 0;
 } 
