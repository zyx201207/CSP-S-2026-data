#include<bits/stdc++.h>
using namespace std;
int n,m,s[500006];
vector<int> e[300006];
int a[300006],a1[300006];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w"stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        e[s[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        int ans=i;
        for(int j=1;j<=m;j++)
        {
        	memset(a,0,sizeof(a));
            for(auto u:e[j]){
            	if(u>=i) break;
            	a[j]++;
			}
			if((e[j].size()-a[j])>=2){
				int u=e[j][e[j].size()-1];
				ans=max(ans,u);
			}
        }
        for(int j=ans;j<=n;j++)
        {
        	//cout<<s[j]<<" ";
        	a1[s[j]]++;
		}
		//cout<<"\n";
    }
    for(int i=1;i<=m;i++)
    {
		cout<<a1[i]<<' '; 
	}
    return 0;
}


