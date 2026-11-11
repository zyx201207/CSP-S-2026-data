////#include<bits/stdc++.h>
////using namespace std;
////
//////
////int n,ans=0,a[500005];//,s[500005];
////long long m,sum;//long long
////
////
//////int check(int l,int r){
//////	
//////	
//////}
////
////int main(){
////	
//////	freopen("crystal.in","r",stdin);
//////	freopen("crystal.out","w",stdout);
////	
////	cin>>n>>m;
////	for(int i=0;i<n;i++){
////		cin>>a[i];
////	}
////	
//////	sum=m;
////	
////	sort(a,a+n);
////	
////	for(int i=0;i<n;i++){
////		
////		sum+=a[i];// a[i]可能等于 0 
////		if(sum%a[i]==0&&sum/a[i]==i+1){
////			
////			ans=max(ans,i+1);
////		}
////		s[i]=sum;
////		
////		
////	}
////	
//////	for(int i=0;i<n;i++){
//////		
//////		sum+=a[i];// a[i]可能等于 0 
//////		if((sum+m)%a[i]==0&&sum/a[i]==i+1){
//////			
//////			ans=max(ans,i+1-j);
//////		}
//////		s[i]=sum;
//////		
//////		
//////	}
////	
////	for(int i=0;i<n;i++){
////		for(int j=i+1;j<n;j++){
////			sum=(s[j]-s[i]);
////			if(sum%a[j-i+1]==0 && (sum/a[j]==j-i+1)){
////				ans=max(ans,i+1-j);
////			}
////		}
////	}
////	
////	cout<<ans;
////	
////	return 0;
////}
//
//
//
//
//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main(){
//	
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	
//	int n,ans=0,a[500005];
//	long long m,sum,sum_1;//long long
//	
//	cin>>n>>m;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//	
//	sum=0;
//	
//	sort(a,a+n);
//	
//	for(int i=0;i<n;i++){
//		
//		sum+=a[i];// a[i]可能等于 0 
////		sum_1=sum+m;
////		if(sum/a[i]!=sum_1/a[i]){
////			ans=max(ans,i+1);
////		}
//		for(int j=0;j<=m;j++){
//			sum_1=sum+j;
//			if(sum_1%a[i]==0&&sum_1/a[i]==i+1){
//			ans=max(ans,i+1);
//			}
//		} 
//		
//		
//		
//	}
//	
//	cout<<ans;
//	
//	return 0;
//}
//
//


//#include<bits/stdc++.h>
//using namespace std;
//
////
//int n,ans=0,a[500005];//,s[500005];
//long long m,sum;//long long
//
//
////int check(int l,int r){
////
////
////}
//
//int main(){
//
////	freopen("crystal.in","r",stdin);
////	freopen("crystal.out","w",stdout);
//
//	cin>>n>>m;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//
////	sum=m;
//
//	sort(a,a+n);
//
//	for(int i=0;i<n;i++){
//
//		sum+=a[i];// a[i]可能等于 0
//		if(sum%a[i]==0&&sum/a[i]==i+1){
//
//			ans=max(ans,i+1);
//		}
//		s[i]=sum;
//
//
//	}
//
////	for(int i=0;i<n;i++){
////
////		sum+=a[i];// a[i]可能等于 0
////		if((sum+m)%a[i]==0&&sum/a[i]==i+1){
////
////			ans=max(ans,i+1-j);
////		}
////		s[i]=sum;
////
////
////	}
//
//	for(int i=0;i<n;i++){
//		for(int j=i+1;j<n;j++){
//			sum=(s[j]-s[i]);
//			if(sum%a[j-i+1]==0 && (sum/a[j]==j-i+1)){
//				ans=max(ans,i+1-j);
//			}
//		}
//	}
//
//	cout<<ans;
//
//	return 0;
//}




#include<bits/stdc++.h>
using namespace std;


int main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n,ans=0,a[500005];
	long long m,sum,sum_1;//long long

	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	sum=0;

	sort(a,a+n);

	for(int z=0; z<n; z++) {
		for(int x=z+1; x<=n; x++) {
			sum=0;
			for(int i=z; i<x; i++) {

				sum+=a[i];	// a[i]可能等于 0
							//		sum_1=sum+m;
							//		if(sum/a[i]!=sum_1/a[i]){
							//			ans=max(ans,i+1);
							//		}
				for(int j=0; j<=m; j++) {
					sum_1=sum+j;
					if(sum_1%a[i]==0&&sum_1/a[i]==i+1-z) {
						ans=max(ans,i+1-z);
					}
				}



			}
		}
	}



	cout<<ans;

	return 0;
}




