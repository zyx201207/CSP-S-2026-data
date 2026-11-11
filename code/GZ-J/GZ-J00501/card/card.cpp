//GZ-J00501 ¸ß´ï 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n ,m,ans,cnt;
int s;
int a[N],b[N],c[N];
bool f[N];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n >> m ;
	for(int i = 1 ; i<=n;i++){
			cin >> a[i];
	}
	for(int i = 1 ; i< n ;i++){
	ans=i;
			for(int j = 1 ; j<=n;j++){
					int t=a[j]; 
					if( f[t] ){
					   for(int g = t;g<j;g++){
		   			   		   b[g]=0;
		   			   		   ans--;
					   }
					   
					   f[j]=false;
					   
					}
					
					if( f[t] == false){
						b[j]=a[j];
					 f[j]=true;
					}
					
		for(int j = 1 ; j<=ans ; j++){
				if(	b[j]==i){
					cnt++;
			}
		}
}
cout << cnt<<' ';	
cnt=0;
}
		
	return 0 ;
}
