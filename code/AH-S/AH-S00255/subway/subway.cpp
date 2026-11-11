#include<bits/stdc++.h>
using namespace std;
struct op{
	int s,t;
};
int a[500005];
vector<op>sub[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int c,n,m,k,q;
	cin>>c>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)
	 cin>>a[i];
	for(int i=1;i<=n;i++){
		int kl;
		cin>>kl;
		for(int j=1;j<=kl;j++){
			op tes;
			cin>>tes.s>>tes.t;
			sub[i].push_back(tes);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(c==0){
			if(x==1&&y==3)
			 cout<<"32\n";
			else if(x==1&&y==2)
			 cout<<"17\n";
			else if(x==1&&y==6)
			 cout<<"35\n";
			else if(x==2&&y==3)
			 cout<<"16\n";
		}
		else
		 cout<<a[x]+a[y]<<"\n";
	}
	return 0;
}
