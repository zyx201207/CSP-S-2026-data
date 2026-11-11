#include<bits/stdc++.h>
using namespace std;
int c,t;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d,a,idx=0,ans=0;
		cin>>n>>d;
		vector<int> island;
		vector<int> minns[n];
		for(int i=0;i<n;i++){
			cin>>a;
			island.push_back(a);
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(!(island[j]-island[i]<=d)) ans++;
				
			}
			
		}
		cout<<ans<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
