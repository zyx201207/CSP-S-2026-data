#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100500;
struct power
{
	ll id;
	int num;
}t[maxn];
ll a[maxn],n,m,cost;
int lastl,lastnum,lasttot;
int cnt=0,tt,ans=0;
int sch(int k)
{
	int tot=0,l=k-1;
	int dl,cl,hh;
	ll pocket=m;//能量 
	bool f=true;
/////////////////////////////////////
	if(k>1&&k<cnt)
	{
		l=lastl;
		tot=lasttot-t[k].num;
		pocket=cost;
		hh=(t[k].id-t[lastl].id);
		if(pocket>=lastnum*hh)
		{
			l--;
			tot+=lastnum;
			pocket-=lastnum*hh;
			//cout<<"king place"<<endl;
		}
		else
		{
			
			 tot+=(pocket/hh);
			 pocket-=lastnum*(pocket/hh);
			 f=false;
		}
	}
	while(l>=1&&f)
	{
		
		dl=t[k].id-t[l].id;
		cl=pocket/dl;
		if(!cl)
			f=false;
		//if(k==6&&l==4)
			//cout<<"king:"<<pocket<<endl;
		if(f)
		{
			
			cl=min(cl,t[l].num);
			
			pocket-=cl*dl;
			//cout<<"来了"<<"  "<<tot<<"   "<<cl<<" ";
			tot+=cl;
			//cout<<tot<<endl;
			if(cl==t[l].num)
				l--;
		}
		cost=pocket+(t[k].id-t[k-1].id)*tot,lasttot=tot,lastl=l,lastnum=t[l].num-cl;
		
	}
	//cout<<tot<<endl;
	
	//cout<<cost<<"   "<<lasttot<<"   "<<lastl<<"   "<<lastnum<<endl;
	return tot;
}


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
			cin>>a[i];
	sort(a+1,a+1+n);
	tt=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
			tt++;
		else
		{
			cnt++;
			t[cnt].id=a[i-1];
			t[cnt].num=tt;
			tt=1;
		}
	}
	cnt++;
	t[cnt].id=a[n];
	t[cnt].num=tt;
	//合并同类相  【以下为数据检查
	//for(int i=1;i<=cnt;i++)
		//cout<<t[i].id<<' '<<t[i].num<<endl;
	for(int i=cnt;i>=1;i--)
	{
		if(lastl<=0&&ans!=0)
			break;
		int hp=sch(i);
		//cout<<i<<"   "<<hp<<"   "<<t[i].num<<endl;
		ans=max(ans,hp+t[i].num);
	}	
	cout<<ans;
	
	
	

	return 0;
}
