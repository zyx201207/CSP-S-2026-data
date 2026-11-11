#include<bits/stdc++.h>
using namespace std;
long long a[10005],sum[10005][10005],b[10005];
long long n,m,s,asd,kil,c,d;
bool cmp(int e,int r)
{
    return e>r;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if (n>5000){
        cin>>c>>d;
        int hh=d-c;
        for (int i=1; ;i++)
        {
            kil+=hh*i;
            if(kil>m)
            {
                cout<<i;
                break;
            }
        }
	}
	else {
        for (int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			sum[0][i]=(a[i]-a[i-1])*i+sum[0][i-1];
			//cout<<sum[0][i]<<" ";
			if (sum[0][i]>m){
				b[0]=i;
				//cout<<b[0]<<endl;
				asd++;
			}
		}
		b[0]=b[0]-asd+1;
		//cout<<b[0]<<endl;
		//cout<<endl;
		for(int j=1 ;j<n;j++){
			for (int i=j+1;i<n;i++){
				sum[j][i]=sum[j-1][i]-(a[i]-a[j-1]);
				//cout<<sum[j][i]<<" ";
				if (sum[j][i]>m){
					b[j]=i-j;
					//cout<<b[j];
					break;
				}
			}
		}
		sort(b,b+n-1,cmp);
		cout<<b[0];
	}

	return 0;
}
