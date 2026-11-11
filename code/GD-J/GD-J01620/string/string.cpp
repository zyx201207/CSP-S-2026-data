#include<bits/stdc++.h>
using namespace std;

int im[200005];
char cm[200005];

int main()
{
    freopen("string6.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>im[i]>>cm[i];
    }

    long long auswer=0;
    int bg=0;
    int ed=n-1;
    while(bg<ed)
    {
        if(cm[bg]==cm[ed])
        {
            int mn=min(im[bg],im[ed]);
            im[bg]-=mn;
            im[ed]-=mn;
            if(im[bg]==0)
                bg++;
            else if(im[ed]==0)
                ed--;
        }
        else
        {
            int mn=min(im[bg],im[ed]);
            im[bg]-=mn;
            im[ed]-=mn;
            auswer+=mn;
            if(im[bg]==0)
                bg++;
            else if(im[ed]==0)
                ed--;
        }
    }

    cout<<auswer;

    return 0;
}
