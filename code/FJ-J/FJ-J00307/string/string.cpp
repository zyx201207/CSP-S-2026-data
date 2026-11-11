#include<iostream>
using namespace std;
struct kuai{
	int a;
	char c; 
};
kuai k[200005];
long long pos[200005];
int main(){
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ldx=1,rdx=1,oldldx=1,oldrdx=1;
	int n=0;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>k[i].a>>k[i].c;
		pos[i]=rdx;
		rdx+=k[i].a;
		
	}
	rdx=rdx-1;
	int kuaildx=1;
	int kuairdx=n;
	long long ans=0;

	while(ldx<=rdx)
	{

		if(ldx==rdx || kuaildx==kuairdx)
		{
			break;
		}
		long long temp=min(1LL*(pos[kuaildx+1]-ldx),-1LL*(pos[kuairdx]-1-rdx));
		oldldx=ldx;
		oldrdx=rdx;
		ldx+=temp;
		rdx-=temp;
	
		if(k[kuaildx].c!=k[kuairdx].c)
		{
			ans+=min(ldx-oldldx,oldrdx-rdx);
		}
		if(ldx>=pos[kuaildx+1])
		{
			kuaildx++;
		}		
		if(rdx<pos[kuairdx])
		{
			kuairdx--;
		}
		
	}
	cout<<ans;
	return 0;
}
