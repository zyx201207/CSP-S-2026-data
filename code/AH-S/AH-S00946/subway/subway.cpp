#include<bits/stdc++.h>
using namespace std;
int  c,n,m,d,q;
struct w{
	int a,b,line;
	int as[100005];
};
struct e{
	int x,y;
};
long long ans=0;
int su[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	w bes[d+5];
	e aes[q+5];
	for(int i=0; i<m; i++)
		cin>>bes[i].a;
	for(int i=0; i<d; i++)	
	{
		cin>>bes[i].line;
		for(int j=0; j<bes[i].line; j++)
		{
			if(j%2==0)
				cin>>bes[i].as[j];
			else
				cin>>bes[i].b;
		}
	}
	for(int i=0; i<q; i++)	
		cin>>aes[i].x>>aes[i].y;
	int s=0;
	for(int i=0; i<q; i++)
	{
		for(int z=0; z<q; z++)
			for(int j=0; j<d; j++)
				for(int k=0; k<d; k++)
					if(bes[i].as[j]=bes[z].as[k])
						su[i]=bes[i].as[j];
		cout<<bes[aes[i].x].a+bes[aes[i].x*2].b+bes[aes[i].y].a+bes[aes[i].y*2].b+bes[su[i]].a+bes[su[i]].b;
		cout<<endl;
	}
	return 0;
}
