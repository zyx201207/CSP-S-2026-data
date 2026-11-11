#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
//bool chart(int a,int b) {return (a==b);}
//bool row(int a,int b)   {return (a==b);}
//bool side(int a,int b)   {return (a==b);}
//bool beside(char a,char b)  {return ((a+1)==b)||(b+1)==a)}
struct node
{
    int row;
    int seat;
};
int str_num(string str)
{
    int ans=0,i=0;
    int len=str.size();
    while(str[i]=='0') i++;
    for(i;i<len;i++) ans=ans*10+(str[i]-'0');
    return ans;
}
bool is_num(char a){return (a>='0'&&a<='9');}
node build(string str)
{
    string str1=str.substr(0,2);
    char str2=str[2];
    int num=0;
    if(str1[0]=='0') num=(str1[1]-'0');
    else num=(str1[0]-'0')*10+(str1[1]-'0');
    node tmp;
    tmp.row=num;tmp.seat=(str2-64);
    return tmp;
}
char al1,al2;
int nu1,nu2;
int side1,side2;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int chart1=str_num(c1);
    int chart2=str_num(c2);
    node node1=build(s1);
    node node2=build(s2);
    if(chart1==chart2) cout<<"1";
    else
    {
        cout<<"0000"<<endl;
        return 0;
    }
    if(node1.row==node2.row) cout<<"1";
    else
    {
        cout<<"000"<<endl;
        return 0;
    }
    if((node1.seat<=3&&node2.seat<=3)||(node1.seat>=4)&&(node2.seat>=4)) cout<<"1";
    else
    {
        cout<<"00"<<endl;
        return 0;
    }
    if(((node1.seat+1)==node2.seat)||((node2.seat+1)==node1.seat)) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}
