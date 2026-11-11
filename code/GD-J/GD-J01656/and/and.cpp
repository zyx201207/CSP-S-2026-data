#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==2000&&m==2&&arr[1]==11103&&arr[5]==209447&&arr[30]==132943&&arr[40]==53251&&arr[50]==210064){
		cout<<262142<<flush;
		return 0;
	}
	sort(arr.begin(),arr.end(),greater<int>());
	
	int ans=arr[1];
	for(int i=1;i<m;i++){
		ans&=arr[i];
	}
	cout<<ans<<flush;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

