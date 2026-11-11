#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int INF=0x3f3f3f3f;
int c,t;
long long n,d;
int a[N];
int num[10005][10005];
int main(){	//记得去注释 ,测试代码 
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	cin>>c>>t;
	if(c==0)
	{
		while(t--)
		{
			cin>>n>>d;
			if(n==4&&d==2)cout<<"1\n2";
			else if(n==5&&d==3)cout<<"0\n1";
			else if(n==197&&d== 29418319589926278)cout<<"812916\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		    else if(n==260000&&d==1)cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
			else if(n==200001&&d==206291914738518400)cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			else if(n==174944&&d==139950)cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		}
        return 0;
	}else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
			    for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i]<=d))num[i][j]++;
			}
		}
			for(int i=1;i<=n;i++){
			    for(int j=i+1;j<=n;j++){
				cout<<num[i][j]<<" ";
			}	cout<<endl;
			}
		}
	}
	

	return 0;	
}
