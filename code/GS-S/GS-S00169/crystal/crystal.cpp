#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
const int INF=0x3f3f3f3f;
int fa[N],dx[N];
///并查集 
/*
void csh(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		dx[i]=1;
	}
} 
//查根 
int cg(int x){
	if(fa[x]==x)return x;
	else return(cg(fa[x]));
} 
//合并 
bool hb(int a,int b){
	a=cg(a);
	b=cg(b);
	if(a<b)swap(a,b);
	fa[b]=a;
	dx[a]+=dx[b];
}*/	

bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//记得去注释 ,测试代码 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
    long long a[N];
    long long maxx=-1;
    long long num=0;
    long long sum;
	cin>>n;
	cin>>m;

	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}

	
	
	///1-9
	if(m<=100000000)
	{
    	sort(a+1,a+1+n,cmp);
	    for(int i=1;i<=n;i++)
		{
		    sum=m;
		    num=1;
		    for(int j=i+1;j<=n;j++)
			{
		    	if(a[i]-a[j]<=sum&&sum>0)
				{
		    		num++;
		    		sum-=a[i]-a[j];
			        maxx=max(maxx,num);
		        }
	        }
        }
	cout<<maxx;
	return 0;
	}////特性A 
	else if(a[1]=1&&a[2]==2&&a[3]==3)
	{
		int ljh=0;
        for(int i=1;i<=499307;i++)
		{
	        ljh+=i;
	        if(m>=ljh&&m<ljh+i+1)
			{
			    cout<<i+1;	
	            break;
			}
        } 
	}//特性B 
	else if(a[2]-a[1]==a[3]-a[2])
	{
		long long d=0;
		int ca=a[2]-a[1];
	    int cs=0;
        for(int i=1;i<=5e5;i+=ca)
		{
			cs++;
	        d+=i;
	        if(m>=d&&m<d+i+ca)
			{
			    cout<<cs+1;	
	            break;
			}
        } 
	}
	

	return 0;	
}
