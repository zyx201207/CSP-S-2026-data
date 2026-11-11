#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long ccc,n;
	cin>>ccc>>n;
	for(int i=1;i<=n;i++){
		
		long long a,b;
		cin>>a>>b;
		long long ed=a;
		for(int j=1;j<=a;j++){
			cin>>arr[j];
//			if(j!=1){
//				if(arr[j]!=arr[j-1]+1){
//					cout<<endl<<arr[j]<<" "<<arr[j-1]<<endl;
//					ed=j-1;
//				}
//			}
			
		}
		int flag=1;
		for(int j=2;j<=a;j++){
			if(arr[j]!=arr[j+1]-1&&flag==1){
				ed=j;
				flag=0;
			}
		}
	
		if(ed-b*2+1<0){
			cout<<0;
		}else{
			cout<<ed-b*2+1<<endl;
		}
		
		
	}

	 
	
	return 0;
}

