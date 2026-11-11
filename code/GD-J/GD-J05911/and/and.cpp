#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
int cnt;
vector<bool> binary[300005];
vector<int> decs;
vector<int> mdecs;
int mywdygs[300005]; 
long long power[50];
void tobinary(int dec,int i)
{
	for(int j=0;j<=50;j++)
	{
	    if(power[j]>dec)
		{
			j--;
			maxx=max(maxx,j);
			binary[i].assign(j+1,0);
			while(dec>0)
			{
				dec-=power[j];
				binary[i][j]=1;
				mywdygs[j]++;
				j--;
			}
			break;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	power[0]=1;
	for(int i=1;i<=50;i++)
		power[i]=power[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int dec;
		cin>>dec;
		decs.push_back(dec);
		tobinary(dec,i);
	}
	
	int idx=maxx;
	maxx=0;
	while(mywdygs[idx]>=m) idx--;
	for(int i=1;i<=n;i++)
		if(binary[i][idx]==1) mdecs.push_back(decs[i]);
	sort(mdecs.begin(),mdecs.end(),greater<int>());
	cnt=mdecs[0];
	for(int i=1;i<m;i++)
		cnt&=mdecs[i];
	cout<<cnt;
	return 0;
}
