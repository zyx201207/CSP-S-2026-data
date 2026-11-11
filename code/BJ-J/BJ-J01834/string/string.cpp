#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int sum=0;
    vector<pair<int,char>> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].first>>v[i].second;
        sum+=v[i].first;
    }

    int wz=0;
    int ans=0;
    int stops=n;
  
    if(sum%2==0)
    {

        int temp=0;
        for(int i=1;i<=n;i++)
        {
			if(temp==sum/2) 
			{
				wz=i-1;
				break;
			}
            if((temp+v[i].first)>sum/2)
            {
				v[i].first-=(temp+v[i].first-sum/2)*2;
                wz=i-1;
     //           cout<<wz;
                break;
            }
            temp+=v[i].first;
        }
        for(int i=1;i<=wz+1;i++)
        {
            while(v[i].first!=0)
            {

                if(v[stops].first>v[i].first)
                {
                    if(v[stops].second!=v[i].second) ans+=v[i].first;
                    v[stops].first-=v[i].first;
                    v[i].first=0;

                }
                else if(v[stops].first==v[i].first)
                {
                    if(v[stops].second!=v[i].second) ans+=v[i].first;
                    v[stops].first=0;
                    v[i].first=0;
                    stops--;
                }
                else{
                    if(v[stops].second!=v[i].second) ans+=v[stops].first;
                    v[i].first-=v[stops].first;
                    v[stops].first=0;

                    stops--;
                }
   //             cout<<ans<<" "<<v[i].first<<endl;
            }


     }
    }
	else if(sum%2==1)
	{
		
        int temp=0;
        for(int i=1;i<=n;i++)
        {
			if(temp==sum/2||temp==(sum/2+1))
			{
				wz=i-1;
				break;
			}
			
            if((temp+v[i].first)>(sum/2+1))
            {
				v[i].first-=(temp+v[i].first-sum/2-1)*2;
				v[i].first-=1;
                wz=i-1;
     //           cout<<wz;
                break;
            }
            temp+=v[i].first;
        }
        for(int i=1;i<=wz+1;i++)
        {
            while(v[i].first!=0)
            {

                if(v[stops].first>v[i].first)
                {
                    if(v[stops].second!=v[i].second) ans+=v[i].first;
                    v[stops].first-=v[i].first;
                    v[i].first=0;
	//				cout<<1;
                }
                else if(v[stops].first==v[i].first)
                {
                    if(v[stops].second!=v[i].second) ans+=v[i].first;
                    v[stops].first=0;
                    v[i].first=0;
                    stops--;
                }
                else{
                    if(v[stops].second!=v[i].second) ans+=v[stops].first;
                    v[i].first-=v[stops].first;
                    v[stops].first=0;

                    stops--;
                }
  //              cout<<ans<<" "<<v[i].first<<" "<<stops<<endl;
            }


     }
	}
//	cout<<sum<<" "<<wz<<endl;
    cout<<ans;

}

