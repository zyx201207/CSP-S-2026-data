#include<bits/stdc++.h>

using namespace std;

const int N=500005;
int n,m;
int shui[N];
int cha[N];
long long int numl=0,numr=0;
bool flagr=false,flagl=false;
int midr,midl;

void dfsl(int mid)
{
	
	numl=0;
	for(int i=1;i<=mid;i++) //计算如果达到mid时需要的步数 
	{
		for(int j=i;j<mid;j++)
		{
			numl+=cha[j];
		}
	}
	if(numl<m)
	{
		flagl=true;//判断是不是已经dfs过了还是第一次就大于m了 
//		cout<<"11"<<" "<<l<<" "<<mid<<" "<<numl<<" "<<flagl<<" "<<l<<" "<<endl;
		return dfsl(mid+1);
	}
	if(numl>=m&&flagl)
	{
		int chong=1;
		while(shui[mid-1]==shui[mid-1+chong])
		{
			chong++;
		}
		midl=mid+chong-1;
//		cout<<"111"<<" "<<、<<" "<<mid<<" "<<numl<<" "<<flagl<<endl;
		return ;
		
	}
//	cout<<"1"<<" "<<l<<" "<<mid<<" "<<numl<<" "<<flagl<<endl;
	return dfsl(mid-1);
}

void dfsr(int mid)
{
	numr=0;
	for(int i=mid;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			numr+=cha[j];
		}
	}
	if(numr<m)
	{
		flagr=true;
//		cout<<"22"<<" "<<r<<" "<<mid<<" "<<numr<<" "<<flagr<<endl;
		return dfsr(mid-1);
	}
	if(numr>=m&&flagr)
	{
		int chong=-1;
		while(shui[mid-1]==shui[mid-1+chong])
		{
			chong--;
		}
		midr=mid+chong+1;
//		cout<<"222"<<" "<<r<<" "<<mid<<" "<<numr<<" "<<flagr<<endl;
		return ;
	}
//	cout<<"2"<<" "<<r<<" "<<mid<<" "<<numr<<" "<<flagr<<endl;
	return dfsr(mid+1);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>shui[i];
	}
	sort(shui,shui+n);
	for(int i=1;i<n;i++) cha[i]=shui[i]-shui[i-1]; 
//	for(int i=1;i<n;i++) cout<<cha[i]<<" "<<endl;
	int mid=(n+1)/2;//中间点 
	int midll,midrr;
	for(int i=0;i<mid-1;i++)
	{
		mid=(n+1)/2;
//		midll=midl-l;
		dfsl(mid);
//		midl=max(midll,midl-l+i-1);
		mid=(n+1)/2;
//		midrr=r-midr;
		dfsr(mid);
//		midr=max(r-i-midr-1,midrr);
	}
	
//	cout<<midl<<" "<<n-midr<<endl;
	cout<<max(n-midr,midl);
	return 0;
 } 
