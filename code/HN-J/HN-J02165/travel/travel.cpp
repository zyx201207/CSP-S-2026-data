#include<bits/stdc++.h >
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,b,c,d;
	char x,y;
	scanf("%d %d%s",&a,&b,&x);
	scanf("%d %d%s",&c,&d,&y);
	if(a==c) cout<<1;
	  else {cout<<0<<0<<0<<0;return 0;}
	if(b==d)
	{
		cout<<1;
		if(x<='C'&&y<='C') 
		{   
		    cout<<1;
		    if(x!='B'&&y!='B') cout<<0;
			 else cout<<1;
		    return 0;
		}
	  	if(x>'C'&&y>'C') {cout<<11;return 0;}
		    else cout<<0<<0;
		return 0;
	}
	else cout<<0<<0;
	if(x==y&&(b==d+1||d==b+1))cout<<1;
    	else cout<<0;
    //fclose(stdin);
	//fclose(stdout);
	return 0;
}    
