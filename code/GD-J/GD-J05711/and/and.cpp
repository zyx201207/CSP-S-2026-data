#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[200007]{};
bool er[200007][62]{};
int num[200007]{};
int MAX=0;

unordered_map<int, bool> flag;

int ans[64];

vector<int> nt;

void ptf()
{
	
	long long zui=0;
	
	for(int i=32;i>=1;i--)
	{
		
		//cout<<ans[i];
		
		if(ans[i]==1)
		{
			
			zui+=pow(2, (i-1));
			
		}
		
	}
	
	//cout<<endl;
	
	cout<<zui;
	return;
	
}

int main()
{
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];
		
		int cnt=0;
		
		while(a[i]!=0)
		{
			
			cnt++;
			
			er[i][cnt]=a[i]%2;
			a[i]/=2;
			
			num[i]=cnt;
			MAX=max(MAX, num[i]);
			
		}
		
	}
	
	int nw=-1;
	
	for(int i=MAX;i>=1;i--)
	{
		
		int jsq=0;
		
		for(int j=1;j<=n;j++)
		{
			
			if(i>num[j])
			{
				
				continue;
				
			}
			
			if(er[j][i]==1)
			{
				
				jsq++;
				nt.push_back(j);
				
			}
			
		}
		
		if(jsq>=m)
		{
			
			ans[i]=1;
			nw=i;
			break;
			
		}
		/*else if(jsq==m)
		{
			
			ans[i]=1;
			
			//cout<<"ans1"<<endl;
			
			ptf();
			return 0;
			
		}*/
		
	}
	
	if(nw==-1)
	{
		
		cout<<"0";
		return 0;
		
	}
	
	for(auto pa:nt)
	{
		
		flag[pa]=true;
		
	}
	
	for(int i=nw-1;i>=1;i--)
	{
		
		int jsq=0;
		vector<int> tmp;
		
		for(auto pa:nt)
		{
			
			if(flag.find(pa)==flag.end()||flag[pa]==false)
			{
				
				continue;
				
			}
			
			//cout<<pa<<" "<<i<<" "<<er[pa][i]<<endl;
			
			if(er[pa][i]==1)
			{
				
				jsq++;
				tmp.push_back(pa);
				
			}
			
		}
		
		if(jsq<m)
		{
			
			continue;
			
		}
		else if(jsq>=m)
		{
			
			flag.clear();
			
			//cout<<"i="<<i<<endl;
			
			ans[i]=1;
			for(auto pa:tmp)
			{
				
				flag[pa]=true; 
				
			}
			
		}
		/*else
		{
			
			//cout<<"ans2"<<endl;
			
			ptf();
			return 0;
			
		}*/
		
	}
	
	//cout<<"ans3"<<endl;
	ptf();
	
	return 0;
	
}
