#include<bits/stdc++.h>
using namespace std;
long long n,m,l[100001],k[100001];
bool a[100001];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<n;i++){
		memset(a,0,n);
		for(int j=i;j<n;j++){
			if(a[l[j]-1]!=1){
			    a[l[j]-1]=1;
//			    cout<<l[j]<<"加入 ";
			}else if(a[l[j]-1]==1){
			    for(int u=l[j]-1;u<m;u++){
			    	a[u]=0;
//			    	cout<<u<<"收 ";
		        }
		        a[l[j]-1]=1;
//		        cout<<l[j]<<"加入 ";
		    }
		}
		for(int j=0;j<m;j++){
			if(a[j]==1)k[j]+=1;
//			cout<<j<<"剩余"<<a[j]<<' ';	
	    }
//		cout<<endl;
	}
	for(int i=0;i<m;i++)cout<<k[i]<<' ';
	return 0;
}
