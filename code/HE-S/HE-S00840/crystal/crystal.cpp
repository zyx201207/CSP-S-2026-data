#include<bits/stdc++.h> 
using namespace std;
#define ll long long
ll n,a[500009],b[500009],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin>>n>>m;
	ll js=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]>b[i+1]){
			m-=b[i+1];
			for(int j=i+1;j<n;j++){
				b[j]=b[j+1];
			}
			n--;
			js++;
		}else{
			m-=b[i];
			for(int j=i;j>1;j--){
				b[j]=b[j-1];
			}
			i++;
			js++;
		}
	}
	cout<<js;
}
	
	///////
//¸ø20·Ö°É




//             /\________/\
//			  /			   \
//			 | 	0	    0   \
//           \		  ,		|
//			  \		___	    1 
//			   \___________/
//
//
//
