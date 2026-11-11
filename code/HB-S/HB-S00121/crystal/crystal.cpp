#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,result=0,l = 1,temp =0;
    cin>>n>>m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            l = 1;
            while (l<=n)
            { 
            if(i == 0) continue;
            if ((arr[i] - arr[j]) + (arr[i] - arr[j+l]) == m)
            {
                temp++;
            }
            l++;
            }
        }
        result = max(result,temp);
        
    }
    cout<<result;
    


    return 0;
}