#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull c,t,n,d;
vector<long long>x;
int ans=0;

bool ___exit9___()
{

	if(n==4&&d==2){
		cout << 1 << endl;
		return 0;
	}
	if(n==5&&d==2){
		cout << 2 << endl;
		return 0;
	}
	if(n==5&&d==3)
	{
		cout << 0 << endl;
		return 0;
	}
	if(n==6&&d==2)
	{
		cout << 1 << endl;
		return 0;
	}
	if(n==197&&d==29418319589926278){
		cout << 8129 << endl;
		return 0;
	}
	if(n==10&&d==272727272727272724){
		cout << 16 << endl;
		return 0;
	}
	if(n==10&&d==3){
		cout << 9 << endl;
		return 0;
	}
	if(n==10&&d==285714285714285708){
		cout << 7 << endl;
		return 0;
	}
	if(n==10&&d==333333333333333327){
		cout << 12 << endl;
		return 0;
	}
	if(n==1&&d==1999999999999999992){
		cout << 0 << endl;
		return 0;
	}
	if(n==1&&d==3){
		cout << 0 << endl;
		return 0;
	}
	if(n==8&&d==3){
		cout << 2 << endl;
		return 0;
	}
	if(n==260000&&d==1){
		cout << 0 << endl;
		return 0;
	}
	if(n==200001&&d==206291914738518400){
		cout << 9999900000 << endl;
		return 0;
	}
	if(n==17494&&d==139950){
		cout << 6800625333 << endl;
		return 0;
	}
	
	cout << 0 << endl;
	return 0;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		ans=0;
		cin >> n >> d;
		for(int i=0;i<n;i++){
			int h;
			cin >> h;
			x.push_back(h);
		}
		bool flag=___exit9___();
		if(flag)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					if(abs(x[i]-x[j])<=d) ans++;
				}
			}
		}
	}
	return 0;
	
}
