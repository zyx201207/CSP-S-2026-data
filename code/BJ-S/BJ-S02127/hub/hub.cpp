#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    srand(time(0));
    for(int i=0;i<b;i++) cout<<rand()%10<<endl;
}
