#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char cy,ce,cyy,cey,py,pe,zy,ze,pyy,pey,kg;
    cin>>cy>>ce>>kg>>py>>pe>>zy>>kg;
    cin>>cyy>>cey>>kg>>pyy>>pey>>ze;
    if(cy==cyy&&ce==cey)
    {
        cout<<1;
        if(py==pyy&&pe==pey)
        {
            cout<<1;
            if(zy>='A'&&zy<='C'&&ze>='A'&&zy<='C')
            {
                cout<<1;
                if(zy-1==ze||zy+1==ze)
                    cout<<1;
                else
                    cout<<0;
            }
            else if(zy>='D'&&zy<='E'&&ze>='D'&&zy<='E')
            {
				cout<<1;
                if(zy-1==ze||zy+1==ze)
                    cout<<1;
                else
                    cout<<0;
            }
            else
                cout<<"00";
        }
		else
			cout<<"000";
    }
    else
        cout<<"0000";
    cout<<endl;
    return 0;
}
