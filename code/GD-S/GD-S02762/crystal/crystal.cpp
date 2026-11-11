#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
int main(){
	//freopen("crystal.in","w",stdin);
	//freopen("crystal.out","r",stdout);
    int count=0; 
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	int a[i];
    	cin>>a[i];
		if(a[i]<=a[i+1]){
		    ans+=a[i+1]-a[i];
			a[i]+=a[i+1];
			count++;
		}
		if(a[i]=a[i+1]){
			count++;
		}
		if(ans==m){
			break;
		}  
	}
	cout<<count-1<<endl;
	return 0;
} 
