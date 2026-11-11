#include<iostream>
using namespace std;
int lst_pos[1145141],a[1145141],times[1145141];
int ans[1145141];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];times[i]=1;
		lst_pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(lst_pos[a[i]]!=i) times[lst_pos[a[i]]]+=times[i];
		else ans[a[i]]+=times[i],times[i+1]+=times[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<endl;
}
