#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,aaa[5];
char x,y;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin >> a >> b >> x >> c >> d >> y;
	if(a==c){
		aaa[1]=1;
		if(b==d)
		{
			aaa[2]=1;
			if(x=='F') x='E';
			if(y=='F') y='E';
			int l=x-'A',r=y-'A';
				if(l==0||l==1||l==2)
				{
					if(r==1||r==2||r==0)
					aaa[3]=1;
				}	
				if(l==3||l==4)
				{
					if(r==3||r==4)
					aaa[3]=1;
				}	
				if( abs((x)-(y))==1&&( (x!=2&&y!=3)||(x!=3&&y!=2) )&&aaa[3]!=0)
				{
					aaa[4]=1;
				}
			}	
		}
	 for(int i=1;i<=4;i++)
	 cout << aaa[i];
	return 0;
}
