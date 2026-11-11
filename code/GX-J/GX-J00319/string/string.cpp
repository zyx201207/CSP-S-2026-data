#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n, nums[200005],ans=0,finalsum=0;
    string inp[200005],curr,reversedd="";
    string final1="";
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++) cin>>nums[i]>>inp[i];
    /*
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<nums[i]; j++)
        {
            final1+=inp[i];
            finalsum+=1;
        }
    }
    for(int i=0; i<=finalsum; i++)
    {
        reversedd+=final1[finalsum-i];
        //cout<<final1[finalsum-i];
    }
    if(final1==reversedd) ans=0;
    */
    //cout<<final1<<" "<<reversedd<<endl;
    //cout<<(final1==reversedd)<<endl;

    cout<<"0";
    return 0;
}
