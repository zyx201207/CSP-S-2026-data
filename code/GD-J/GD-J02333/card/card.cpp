#include<bits/stdc++.h>
using namespace std;
void pm(int &x,int y)
{
    x%=y;
    if(x==0) x=y;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m,i,j;
	cin>>n>>m;
	vector <int> c(n+2);
	vector <bool> dc(n+2);
	vector <int> d(n+1);
	vector <int> o(n+2);
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==c[i-1] && i!=1)
        {
            --i;--n;
            //cout<<i<<" "<<c[i]<<endl;
            continue;
        }
		//cout<<i<<endl;
	}
	//cout<<"cin end================="<<endl;

	int k,kp;
	for(i=1;i<=n;i++)
	{
	    kp=1;
        for(k=1;k<=n;k++)
        {
            pm(kp,n);
            dc[c[kp]]=0;
            kp++;
        }
        d.clear();
		for(j=i;j<=n;j++)
		{
			if(dc[c[j]])
			{
				kp=j;
				for(k=1;k<=n;k++)
				{
				    pm(kp,n);
					dc[c[kp]]=0;
				    kp++;
				}
				d.clear();
			}
			d.push_back(c[j]);
			dc[c[j]]=1;

			/*
		    cout<<endl<<i<<" "<<j<<endl;
		    for(k=0;k<d.size();k++)
            {
                cout<<d[k]<<" ";
            }cout<<endl;
            */

		}
		for(j=0;j<d.size();j++)
        {
            o[d[j]]++;
        }
	}
	for(i=1;i<=m;i++) cout<<o[i]<<" ";

	fclose(stdin);
	fclose(stdout);
}
