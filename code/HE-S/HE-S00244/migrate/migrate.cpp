#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int T=0;T<t;T++){
		int  n,d;
		cin>>n>>d;
		int sum=0;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((arr[i]+d<arr[j])&&(arr[i]+d+d>arr[j])){
					if((arr[j]-arr[i]-d)%2==d%2){
						continue;
					}
					    sum++;
//					cout<<arr[i]<<' '<<arr[j]<<endl;
				}
				if(arr[i]+d+d<=arr[j]){
					break;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5


