#include<bits/stdc++.h>
using namespace std;
bool a=false;
int s,n,m,num[20],sa[120],ans;
int main(){
	cin>>n>>m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>num[i];
		s<=num[i];
		for(int j=0;j<=20;j++){
			
			if(num[i]-2^s>=0){
				a=true;
				sa[i]=1;
				s--;
				num[i]=sa[i];
				num[i]=num[i]-2^s;
			}	
			else{
				s--;
			}
			if(num[i]&sa[i]!=0){
				ans++;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
