#include<iostream>
#include<ostream>
using namespace std;
int main()
{
    
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int t=0,t1=0;
    for(int i=0;i<m;i++)
    {
        t1=t;
        t=a[i] and a[i+1];
        if(t>t1){
            t=a[i] and a[i+1];
        }else{
            t=t1;
        }
    }
    cout << t << endl;
    
}