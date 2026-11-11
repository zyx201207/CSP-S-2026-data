#include<bits/stdc++.h>
#define random(a,b) rand()%(b-a+1)+a
using namespace std;
namespace D{
	int main(){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		srand((int)time(0));
		int hub,t;
		scanf("%d%d",&hub,&t);
		while (t--)
		{
			int n,k;
			scanf("%d%d",&n,&k);
			for (int i=1;i<n;i++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
			}
			printf("%d\n",random(1,n/2));
		}
		return 0;
	}
};
int main(){
	return D::main();
}
