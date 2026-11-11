#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,d;
int count = 0;


int f(int x,int y){
    if(x<=1) return 0;
    if(x=2) return 1;
    
    return f(x-1,y)+f(x,y);
}

int main()

{
    cin>>c>>t;
    int arr[][c]={};
    int arr1[t][2];
    for (int i = 0; i < t; i++)
    {
        cin>>n>>d;
        arr1[i][0] = n;
        arr1[i][1] = d;
        for (int j = 0; j < arr1[i][0]; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    return 0;
}