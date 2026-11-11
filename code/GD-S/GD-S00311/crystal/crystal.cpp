#include<bits/stdc++.h>

using namespace std;
//priority_queue<>

long long q[(int)5e5];
long long nums[(int)5e5];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();	
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	//long long nums[n];
	//long long q[(int)5e5];
	nums[0] = 0;
	q[0] = 0;
	//cout<<"!";
	//return 0;
	for (int i = 1;i <= n;i++)cin>>nums[i];
	sort(nums+1,nums+n+1);
	for (int i = 1;i <= n;i++)q[i] = nums[i]+q[i-1];
	//cout<<q[1]<<endl;
    //cout<<"!";
	int mx = -1e9;
	
	for (int i = 1;i <= n;i++){
		//cout<<"运行到i="<<i<<endl;
		int l = 1,r = i;
		while (l <= r){
			int mid = (l+r)/2;
			long long va = (i-mid+1)*nums[i] + q[mid-1] -q[i];
			//cout<<"从"<<mid<<"到"<<i<<"代价是"<<va<<endl;
			if (va > m)l = mid + 1;
			else {
				mx = max(i-mid+1,mx);
				//if (mx ==i-mid+1 )cout<<"选择"<<i<<" "<<mid<<"代价为"<<va<<endl;
				r = mid-1;
			}
		}
	}
	cout<<mx;
	
	return 0;
} 

	
	
	/*
	int s[] = {1,2,3,4,5,6,7};
    cout<<upper_bound(s,s+5,2)-s<<endl;
	cout<<lower_bound(s,s+5,2)-s;
	*/
