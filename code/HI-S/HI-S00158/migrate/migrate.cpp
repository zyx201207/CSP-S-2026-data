#include<bits/stdc++.h>
using namespace std;

int arr[10005];
struct s{
	int v;vector<int> c;
};


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	
	while(t--){
		int n,d;
		cin>>n>>d;
		
		for(int i=0;i<n;i++)cin>>arr[i];
		int cnt=0;
		
		for(int i=0;i<n-2;i++){
			if(arr[i]+d>arr[i+1]&&arr[i]+d>=arr[i+2]){
				cnt++;
			}
		}
		if(cnt>2){
			cout<<0<<"\n";
		}else
		cout<<cnt-1<<"\n";
	}


	
	
	return 0;
}

