#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool near[6][6]={{0,1,0,0,0,0},{1,0,1,0,0,0},{0,1,0,0,0,0},{0,0,0,0,1,0},{0,0,0,1,0,0}};
    bool dao[6][6]={{0,1,1,0,0,0},{1,0,1,0,0,0},{1,1,0,0,0,0},{0,0,0,0,1,0},{0,0,0,1,0,0}};
    string ashu="",azuo="",bshu="",bzuo="";
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ashu>>azuo>>bshu>>bzuo;
    bool che_xiang=false,pai=false,lie=false;
    if(ashu==bshu)
    {
        che_xiang=true;
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(che_xiang&&azuo[0]==bzuo[0]&&azuo[1]==bzuo[1])
    {
        pai=true;
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    long long awei=azuo[2]-'A',bwei=bzuo[2]-'A';
    if(che_xiang&&pai&&dao[awei][bwei]==true)
    {
        lie=true;
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    if(che_xiang&&pai&&lie&&near[awei][bwei]==true)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
